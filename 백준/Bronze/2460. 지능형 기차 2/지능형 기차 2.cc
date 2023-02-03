#include <iostream>

using namespace std;

int getMax(int a, int b)
{
    if(a>=b) return a;
    else return b;
}

int main()
{
    int max=0, now=0, in, out;

    for(int i=0;i<10;i++)
    {
        scanf("%d %d", &out, &in);
        now -= out;
        now += in;
        
        max = getMax(max, now);
    }

    printf("%d", max);

    return 0;
}