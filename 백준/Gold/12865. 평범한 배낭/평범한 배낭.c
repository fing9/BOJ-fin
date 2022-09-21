# include <stdio.h>

int max(int X,int Y)
{
    if(X>=Y)
        return X;
    else
        return Y;
}

int main()
{
    int N, K, i, j, answer=0;
    int D[100001][101], W[100001], V[100001];
    
    scanf("%d %d",&N,&K);
    for(i=1;i<=N;i++)
        scanf("%d %d",&W[i],&V[i]);
    for(i=0;i<=K;i++)
        D[i][0]=0;
    for(i=0;i<=N;i++)
        D[0][i]=0;
    
    for(i=1;i<=K;i++)
    {
        for(j=1;j<=N;j++)
        {
            if(i>=W[j])
            {
                D[i][j]=max(D[i][j-1],D[i-W[j]][j-1]+V[j]);
            }
            else
            {
                D[i][j]=D[i][j-1];
            }
        }
    }
    
    for(i=1;i<=K;i++)
    {
        if(D[i][N]>answer)
            answer=D[i][N];
    }
    
    printf("%d",answer);
    return 0;
}