# include <stdio.h>
int DP[1001][10];

int main()
{
    int N, i, j, k, sum=0;
    scanf("%d", &N);
    
    for(i=0;i<10;i++)
        DP[1][i] = 1;
    
    for(i=0;i<=N;i++)
        DP[i][9] = 1;
    
    for(i=2;i<=N;i++)
    {
        for(j=8;j>=0;j--)
        {
            for(k=j;k<10;k++)
            {
                DP[i][j] += DP[i-1][k];
                DP[i][j] %= 10007;
            }
        }
    }
    
    for(i=0;i<10;i++)
    {
        sum += DP[N][i];
        sum %= 10007;
    }
    
    printf("%d",sum);
    
    return 0;
}