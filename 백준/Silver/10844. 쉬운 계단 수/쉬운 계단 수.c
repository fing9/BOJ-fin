# include <stdio.h>
long long DP[101][10];

int main()
{
    int N, i, j;
    long long answer=0;
    scanf("%d",&N);
    
    for(i=0;i<10;i++)
        DP[1][i] = 1;
    
    for(i=2;i<=N;i++)
    {
        for(j=0;j<10;j++)
        {
            if(j==0)
            {
                DP[i][j] = DP[i-1][j+1] % 1000000000;
            }
            else if(j==9)
            {
                DP[i][j] = DP[i-1][j-1] % 1000000000;
            }
            else
            {
                DP[i][j] = (DP[i-1][j-1] + DP[i-1][j+1]) % 1000000000;
            }
        }
    }
    
    for(i=1;i<10;i++)
    {
        answer += DP[N][i];
        answer %= 1000000000;
    }
    printf("%lld",answer);
    
    return 0;
}