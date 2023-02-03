# include <stdio.h>

int main()
{
    int N, K, a=1, b=1, i;
    scanf("%d %d",&N,&K);
    
    for(i=0;i<K;i++)
        a*=N-i;
    for(i=K;i>0;i--)
        b*=i;
    
    printf("%d",a/b);
    
    return 0;
}