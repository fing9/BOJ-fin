# include <stdio.h>
# include <string.h>

int DP[1001];

int tiling(int N)
{
    int i;
    
    for(i=3;i<=N;i++)
    {
        DP[i] = (DP[i-1] + DP[i-2]) % 10007;
    }
    
    return DP[N];
}


int main()
{
    int N;
    scanf("%d",&N);
    memset(DP,-1,sizeof(DP));
    DP[1] = 1;
    DP[2] = 2;
    printf("%d",tiling(N));
    
    return 0;
}