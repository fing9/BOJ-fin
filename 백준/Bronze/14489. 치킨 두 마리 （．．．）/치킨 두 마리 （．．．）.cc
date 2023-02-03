#include <iostream>

using namespace std;

int main()
{
    long long A, B, C;
    scanf("%lld %lld", &A, &B);
    scanf("%lld", &C);
    
    if(C * 2 > A + B)
        printf("%lld", A+B);
    else
        printf("%lld", A+B-C-C);
    
    return 0;
}