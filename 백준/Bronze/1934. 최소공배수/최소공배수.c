# include <stdio.h>

int gcd(int x, int y)
{
    int tmp, n;
    
    if(x<y)
    {
        tmp=x;
        x=y;
        y=tmp;
    }
    
    while(y!=0)
    {
        n=x%y;
        x=y;
        y=n;
    }
    
    return x;
}

int lcm(int a, int b)
{
    return (a*b) / gcd(a,b);
}

int main()
{
    int T, a, b;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&a,&b);
        
        printf("%d\n",lcm(a,b));
    }
    
    return 0;
}