# include <stdio.h>
int home[1001][3];
int DP[1001][3];

int Min(int X, int Y, int Z)
{
    if(X<=Y && X<=Z)
        return X;
    else if(Y<=X && Y<=Z)
        return Y;
    else if(Z<=X && Z<=Y)
        return Z;
}

int Min_2(int X, int Y)
{
    if(X<=Y)
        return X;
    else
        return Y;
}

int main()
{
    int N, i, j, lower_price=1000001;
    scanf("%d",&N);
    for(i=0;i<1001;i++)
        memset(DP[i],-1,sizeof(DP[i]));
    for(i=1;i<=N;i++)
    {
        scanf("%d %d %d",&home[i][0],&home[i][1],&home[i][2]);
    }
    DP[1][0] = home[1][0];
    DP[1][1] = home[1][1];
    DP[1][2] = home[1][2];
    for(i=1;i<N;i++)
    {
        DP[i+1][0] = home[i+1][0] + Min_2(DP[i][1],DP[i][2]);
        DP[i+1][1] = home[i+1][1] + Min_2(DP[i][0],DP[i][2]);
        DP[i+1][2] = home[i+1][2] + Min_2(DP[i][0],DP[i][1]);
    }
    printf("%d",Min(DP[N][0],DP[N][1],DP[N][2]));
    
    return 0;
}