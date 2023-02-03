#include <iostream>

using namespace std;

int main()
{
    unsigned long long n, S, sum;
    
    scanf("%llu", &n);
    sum = n * (n + 1) * 2;
    n -= 1;
    S = n * (n + 1) * 2;
    
    printf("%llu", sum - S);
    
    return 0;
}