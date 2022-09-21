#include<stdio.h>
int main()
{
    int c[10001]={0,}, n, k, i, j;
    unsigned long long D[10001]={0,};
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
        scanf("%d",&c[i]);
    D[0]=1;
    for(i=1;i<=n;i++)
    {
        for(j=c[i];j<=k;j++)
            D[j] += D[j-c[i]];
    }
    printf("%llu",D[k]);
}