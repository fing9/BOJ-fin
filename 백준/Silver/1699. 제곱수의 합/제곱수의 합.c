# include <stdio.h>

int main()
{
    int N, num, min=987654321, DP[100001]={0,}, i, j;
    scanf("%d",&N);
    DP[0]=0;
    DP[1]=1;
    for(i=2;i<=N;i++)
    {
        min=987654321;
        for(j=1;(j*j)<=i;j++)
        {
            if(DP[i-(j*j)]<min)
                min=DP[i-(j*j)]+1;
        }
        DP[i]=min;
    }
    printf("%d",DP[N]);
    return 0;
}