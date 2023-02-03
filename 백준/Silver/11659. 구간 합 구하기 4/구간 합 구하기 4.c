# include <stdio.h>

int main()
{
    int N, M, i;
    int a, b;
    int dp[100001]={0,}, num[100001]={0,};
    scanf("%d %d",&N,&M);
    for(i=1;i<=N;i++)
    {
        scanf("%d",&num[i]);
    }
    dp[1]=num[1];
    for(i=2;i<=N;i++)
    {
        dp[i]=dp[i-1]+num[i];
    }
    for(i=1;i<=M;i++)
    {
        scanf("%d %d",&a,&b);
        if(a>1)
            printf("%d\n",dp[b]-dp[a-1]);
        else
            printf("%d\n",dp[b]);
    }
    return 0;
}