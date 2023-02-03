# include <stdio.h>
int dp[41][2];

void fibonacci(int n)
{
    if(n==0)
    {
        dp[0][0] = 1;
        dp[0][1] = 0;
    }
    else if(n==1)
    {
        dp[1][0] = 0;
        dp[1][1] = 1;
    }
    else if(dp[n-1][0]!=-1 && dp[n-2][0]!=-1)
    {
        dp[n][0] = dp[n-1][0] + dp[n-2][0];
        dp[n][1] = dp[n-1][1] + dp[n-2][1];
    }
    else
    {
        fibonacci(n-1);
        fibonacci(n);
    }
}

int main()
{
    int T, N ,i;
    scanf("%d",&T);
    memset(dp,-1,sizeof(dp));
    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = 1;
    for(i=0;i<T;i++)
    {
        scanf("%d",&N);
        fibonacci(N);
        printf("%d %d",dp[N][0],dp[N][1]);
        if(i!=T-1)
            printf("\n");
    }
    return 0;
}