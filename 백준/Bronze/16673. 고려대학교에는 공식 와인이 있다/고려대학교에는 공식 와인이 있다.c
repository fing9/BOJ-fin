# include <stdio.h>

int main()
{
    int n, K, P, answer=0;
    scanf("%d %d %d",&n,&K,&P);
    for(int i=1;i<=n;i++)
        answer += (K*i)+(P*i*i);
    printf("%d",answer);
    return 0;
}