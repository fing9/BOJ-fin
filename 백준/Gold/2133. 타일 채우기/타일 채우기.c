# include <stdio.h>

int main()
{
    int N, i, j;
    unsigned long long D[31]={0,};
    scanf("%d",&N);
    D[2]=3;
    if(N%2==0)
    {
        for(i=4;i<=N;i+=2)
        {
            D[i] += D[i-2]*3 + 2;
            for(j=4;j<=i;j+=2)
                D[i] += D[i-j]*2;
        }
        printf("%llu",D[N]);
    }
    else
    {
        printf("0");
    }
    return 0;
}