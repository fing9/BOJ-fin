# include <stdio.h>
unsigned long long DP[91][2];

int main()
{
    int N, i;
    scanf("%d",&N);
    DP[1][0] = 0;
    DP[1][1] = 1;
    for(i=2;i<=N;i++)
    {
        DP[i][0] = DP[i-1][1] + DP[i-1][0];
        DP[i][1] = DP[i-1][0];
    }
    printf("%llu",DP[N][0]+DP[N][1]);
    return 0;
}