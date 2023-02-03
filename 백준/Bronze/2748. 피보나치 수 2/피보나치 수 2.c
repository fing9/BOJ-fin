# include <stdio.h>
unsigned long long dp[91];

void fibonacci(int N)
{
    if(N == 1)
    {
        dp[1]=1;
    }
    else if(dp[N-1]!=-1 && dp[N-2]!=-1)
    {
        dp[N] = dp[N-1] + dp[N-2];
    }
    else
    {
        fibonacci(N-1);
        fibonacci(N);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    fibonacci(n);
    printf("%llu",dp[n]);
    return 0;
}