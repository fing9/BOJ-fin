#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long N, M;
    
    scanf("%lld %lld", &N, &M);
    
    printf("%lld", abs(N-M));
    
    return 0;
}