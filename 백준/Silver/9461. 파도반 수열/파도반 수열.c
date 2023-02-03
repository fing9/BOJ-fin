# include <stdio.h>
int N;
unsigned long long DP[101];

int main()
{
    int T, i, j;
    DP[1] = 1;
    DP[2] = 1;
    DP[3] = 1;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&N);
        if(N==1)
            printf("1\n");
        else if(N==2)
            printf("1\n");
        else if(N==3)
            printf("1\n");
        else
        {
            for(j=1;j<=N-3;j++)
            {
                DP[j+3] = DP[j]+DP[j+1];
            }
            printf("%llu\n",DP[N]);
        }
    }
    return 0;
}