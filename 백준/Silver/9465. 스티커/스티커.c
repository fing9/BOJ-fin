# include <stdio.h>
# include <string.h>

int Max(int X, int Y)
{
    if(X>=Y)
        return X;
    else
        return Y;
}

int main()
{
    int T, n, stk[100001][2], DP[100001][2], i, j, up_down = 1;
    
    scanf("%d",&T);
    
    for(i=0;i<T;i++)
    {
        for(j=1;j<=100001;j++)
        {
            memset(stk[i],0,sizeof(stk[i]));
            memset(DP[i],0,sizeof(DP[i]));
        }
        scanf("%d",&n);
        for(j=1;j<=n;j++)
            scanf("%d",&stk[j][1]);
        for(j=1;j<=n;j++)
            scanf("%d",&stk[j][0]);
        DP[n][0] = stk[n][0];
        DP[n][1] = stk[n][1];
        if(n==1)
        {
            printf("%d\n",Max(stk[1][0],stk[1][1]));
            continue;
        }
        DP[n-1][0] = stk[n-1][0]+ DP[n][1];
        DP[n-1][1] = stk[n-1][1]+ DP[n][0];
        if(n==2)
        {
            printf("%d\n",Max(DP[n-1][0],DP[n-1][1]));
            continue;
        }
        for(j=n-2;j>=1;j--)
        {
            if(DP[j+1][0]>=DP[j+2][0])
            {
                DP[j][1] = stk[j][1] + DP[j+1][0];
            }
            else
            {
                DP[j][1] = stk[j][1] + DP[j+2][0];
            }
            if(DP[j+1][1]>=DP[j+2][1])
            {
                DP[j][0] = stk[j][0] + DP[j+1][1];
            }
            else
            {
                DP[j][0] = stk[j][0] + DP[j+2][1];
            }
        }
        printf("%d\n",Max(DP[1][1],DP[1][0]));
    }
    
    return 0;
}