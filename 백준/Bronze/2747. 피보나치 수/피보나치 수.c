# include <stdio.h>

int main()
{
    int n, i;
    unsigned long long DP[46]={0,};
    DP[1]=1;
    
    scanf("%d",&n);
    
    for(i=2;i<=n;i++)
        DP[i]=DP[i-1]+DP[i-2];
    
    printf("%llu",DP[n]);
    
    return 0;
}