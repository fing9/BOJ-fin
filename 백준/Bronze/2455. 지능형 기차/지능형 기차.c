# include <stdio.h>

int main()
{
    int max=0, now=0, a, b;
    while(~scanf("%d %d",&a,&b))
    {
        now+=b-a;
        if(now>max)
            max=now;
    }
    printf("%d",max);
    return 0;
}