# include <stdio.h>

int main()
{
    int N, arr[1001], DP[1001];
    int Max, answer=0, i, j;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%d",&arr[i]);
        DP[i] = 1;
    }
    Max = 0;
    if(N==1)
    {
        printf("1");
        return 0;
    }
    else
    {
        for(i=N-2;i>=0;i--)
        {
            for(j=i+1;j<N;j++)
            {
                if(arr[i]<arr[j] && DP[j]>Max)
                {
                    Max = DP[j];
                }
            }
            DP[i] = Max + 1;
            Max = 0;
        }
    }
    
    for(i=0;i<N;i++)
    {
        if(DP[i]>answer)
            answer = DP[i];
    }
    
    printf("%d",answer);
    
    return 0;
}