# include <stdio.h>

int main()
{
    int N, arr[1001], DP[1001], DP2[1001];
    int Max, answer=0, i, j;
    scanf("%d",&N);
    
    for(i=0;i<N;i++)
    {
        scanf("%d",&arr[i]);
        DP[i] = 1;
        DP2[i] = 1;
    }
    
    if(N==1)
    {
        printf("1");
        return 0;
    }
    else
    {
        for(i=1;i<N;i++)
        {
            Max = 0;
            for(j=i-1;j>=0;j--)
            {
                if(arr[i]>arr[j] && DP[j]>Max)
                    Max = DP[j];
            }
            DP[i] = Max + 1;
        }
        for(i=N-2;i>=0;i--)
        {
            Max = 0;
            for(j=i+1;j<N;j++)
            {
                if(arr[i]>arr[j] && DP2[j]>Max)
                    Max = DP2[j];
            }
            DP2[i] = Max + 1;
        }
    }
    
    for(i=0;i<N;i++)
    {
        if(DP[i]+DP2[i]-1>answer)
            answer = DP[i]+DP2[i]-1;
    }
    printf("%d",answer);
    
    return 0;
}