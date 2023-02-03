#include <iostream>
using namespace std;

int max(int a, int b, int c)
{
    if(a>=b && a>=c)
        return a;
    else if(b>=a && b>=c)
        return b;
    else
        return c;
}

int main()
{
    int a, b, c, ret;
    
    scanf("%d %d %d",&a ,&b ,&c);
    
    if(a==b && b==c)
    {
        ret = 10000 + (a*1000);
    }
    else if(a==b || b==c || a==c)
    {
        if(a==b)
        {
            ret = 1000 + (a*100);
        }
        else if(b==c)
        {
            ret = 1000 + (b*100);
        }
        else
        {
            ret = 1000 + (c*100);
        }
    }
    else
    {
        ret = max(a,b,c)*100;
    }
    
    printf("%d",ret);
    
    return 0;
}