# include <stdio.h>
# include <string.h>
int DP[1001][1001];
int N, K;

int main()
{
    int i, j;
    scanf("%d %d",&N,&K);
    
    for(i=0;i<=1000;i++) // reset
        memset(DP[i],0,sizeof(DP[i]));
    
    DP[1][0]=1;
    for(i=0;i<=1000;i++)
    {
        DP[i][0]=1;
        DP[i][i]=1;
    }
    
    for(i=2;i<=1000;i++)
    {
        for(j=1;j<=i;j++)
            DP[i][j] = (DP[i-1][j-1] + DP[i-1][j]) % 10007;
    }
    
    printf("%d",DP[N][K]);
    
    return 0;
}