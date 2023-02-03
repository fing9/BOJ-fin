# include <stdio.h>
# include <string.h>

int max(int X, int Y)
{
    if(X>=Y)
        return X;
    else
        return Y;
}

int main()
{
    int DP[1001][1001], candy[1001][1001];
    int N, M, i, j;
    for(i=0;i<1001;i++)
    {
        memset(DP[i],0,sizeof(DP[i]));
        memset(candy[i],0,sizeof(candy[i]));
    }
    
    scanf("%d %d",&N,&M);
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=M;j++)
            scanf("%d",&candy[i][j]);
    }
    
    for(i=N;i>=1;i--)
    {
        for(j=M;j>=1;j--)
        {
            if(i==N && j==M)
                DP[i][j] = candy[i][j];
            else if(i==N)
                DP[i][j] = DP[i][j+1] + candy[i][j];
            else if(j==M)
                DP[i][j] = DP[i+1][j] + candy[i][j];
            else
                DP[i][j] = max(DP[i+1][j],DP[i][j+1]) + candy[i][j];
        }
    }
    
    printf("%d",DP[1][1]);
    
    return 0;
}