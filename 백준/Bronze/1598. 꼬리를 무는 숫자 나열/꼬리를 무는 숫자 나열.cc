#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    long long A, B;
    long long ay, ax, by, bx;
    
    scanf("%lld %lld", &A, &B);
    
    ay = (A % 4);
    ax = (A / 4) + 1;
    if(A % 4 == 0)
    {
        ax--;
        ay = 4;
    }
        
    by = (B % 4);
    bx = (B / 4) + 1;
    if(B % 4 == 0)
    {    
        bx--;
        by = 4;
    }
    
    printf("%lld", abs(ay - by) + abs(ax - bx));
    
    return 0;
}