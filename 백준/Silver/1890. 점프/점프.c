# include <stdio.h>
# include <string.h>
int N;
long long DP[120][120], a[120][120];

long long solve(int x, int y)
{
    if(a[x][y]==0 && (x!=N || y!=N))
        return 0;
    if(DP[x][y]!=-1)
        return DP[x][y];
    if(x==N && y==N)
        return 1;
    if(x>N || y>N)
        return 0;
    
    return DP[x][y] = solve(x+a[x][y],y) + solve(x,y+a[x][y]);

}

int main()
{
    int i, j;
    scanf("%d",&N);
    
    for(i=1;i<=N;i++)
    {
        memset(DP[i],-1,sizeof(DP[i]));
        memset(a[i],0,sizeof(a[i]));
    }
    
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
            scanf("%lld",&a[i][j]);
    }
    
    solve(1,1);
    
    printf("%lld",DP[1][1]);
    
    return 0;
}