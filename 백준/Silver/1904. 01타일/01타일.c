# include <stdio.h>
int DP[1000001];

int main()
{
    int N, i;
    DP[1]=1;
    DP[2]=2;
    scanf("%d",&N);
    for(i=3;i<=N;i++)
    {
        DP[i] = (DP[i-1]%15746) + (DP[i-2]%15746);
        DP[i] %= 15746;
    }
    printf("%d",DP[N]);
    return 0;
}