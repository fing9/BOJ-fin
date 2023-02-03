# include <stdio.h>

int main()
{
    long long ret;
    int N, B, C, i;
    int num[1000000]={0,};
    scanf("%d",&N);
    for(i=0;i<N;i++)
        scanf("%d",&num[i]);
    scanf("%d %d",&B,&C);
    ret=N;
    for(i=0;i<N;i++)
    {
        num[i]-=B;
        if(num[i]>0)
        {
            if(num[i]%C==0)
                ret+=num[i]/C;
            else
                ret+=(num[i]/C)+1;
        }
    }
    
    printf("%lld",ret);
    
    return 0;
}