# include <stdio.h>
# include <string.h>

int main()
{
    int N, arr[100002], DP[100001], i;
    int answer=-100000001;
    scanf("%d",&N);
    for(i=1;i<=N;i++)
        scanf("%d",&arr[i]);
    
    DP[N] = arr[N];
    
    for(i=N-1;i>0;i--)
    {
        if(DP[i+1]>0)
        {
            DP[i] = DP[i+1] + arr[i];
        }
        else
        {
            DP[i] = arr[i];
        }
    }
    
    for(i=1;i<=N;i++)
    {
        if(DP[i]>answer)
            answer=DP[i];
    }
    
    printf("%d",answer);
    
    return 0;
}