# include <stdio.h>
# include <string.h>
int DP[501][501];
int Num[501][501];
int N;

int Max(int X, int Y)
{
    if(X>=Y)
        return X;
    else
        return Y;
}

int main()
{
    int i, j;
    for(i=0;i<501;i++)
        memset(DP[i],-1,sizeof(DP[i]));
    scanf("%d",&N);
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=i;j++)
            scanf("%d",&Num[i][j]);
    }
    
    for(i=1;i<=N;i++)
    {
        DP[N][i] = Num[N][i];
    }
    
    for(i=N-1;i>=1;i--)
    {
        for(j=N-1;j>=1;j--)
        {
            DP[i][j] = Num[i][j] + Max(DP[i+1][j],DP[i+1][j+1]);
        }
    }
    
    printf("%d",DP[1][1]);
    return 0;
}