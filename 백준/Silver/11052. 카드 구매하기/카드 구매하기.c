# include <stdio.h>

int max(int X, int Y)
{
    if(X>=Y)
        return X;
    else
        return Y;
}

int main()
{
    int card[1001]={0,}, DP[1001]={0,}, N, i, j;
    
    scanf("%d",&N);
    for(i=1;i<=N;i++)
        scanf("%d",&card[i]);
    
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=i;j++)
        {
            DP[i] = max(DP[i],DP[i-j]+card[j]);
        }
    }
    
    printf("%d",DP[N]);
    return 0;
}