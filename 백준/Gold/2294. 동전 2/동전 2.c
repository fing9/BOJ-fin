# include <stdio.h>

int min(int X, int Y)
{
    if(X<=Y)
        return X;
    else
        return Y;
}

int main()
{
    int DP[10001]={0,}, coin[10001]={0,}, n, k, i, j;
    scanf("%d %d",&n,&k);
    
    for(i=1;i<=n;i++)
        scanf("%d",&coin[i]);
    
    for(i=1;i<=k;i++)
        DP[i]=100001; 
    
    for(i=1;i<=n;i++)
    {
        for(j=coin[i];j<=k;j++)
        {
            DP[j]=min(DP[j],DP[j-coin[i]]+1);
        }
    }
    
    if(DP[k]==100001)
        printf("-1");
    else
        printf("%d",DP[k]);
    
    return 0;
}