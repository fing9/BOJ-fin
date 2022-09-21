# include <stdio.h>

int main()
{
    int N, K, i, j, l;
    unsigned long long DP[201][201];
    scanf("%d %d",&N,&K);
    
    for(i=0;i<=200;i++)
    {
        for(j=0;j<=200;j++)
            DP[i][j] = 0;
    }
    
    for(i=0;i<=200;i++)
    {
        DP[1][i] = 1;
    }
    
    for(i=1;i<=K;i++)
    {
        for(j=0;j<=N;j++)
        {
            for(l=j;l>=0;l--)
            {
                DP[i][j] += DP[i-1][j-l];
                DP[i][j] %= 1000000000;
            }
        }
    }
    
    printf("%llu",DP[K][N]);
    return 0;
}