# include <stdio.h>
# include <string.h>
long long DP[11];
 
void solve(int N) // top-down
{
 
    if(DP[N-1]!=-1 && DP[N-2]!=-1 && DP[N-3]!=-1)
    {
        DP[N] = DP[N-1] + DP[N-2] + DP[N-3];
        return;
    }
    if(N > 3)
    {
        solve(N-1);
        solve(N);
    }
}
 
int main()
{
    int T, N;
    memset(DP,-1,sizeof(DP));
    DP[1]=1;
    DP[2]=2;
    DP[3]=4;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d",&N);
        solve(N);
        printf("%lld",DP[N]);
        if(i!=T-1)
            printf("\n");
    }
    return 0;
}