#include <iostream>

using namespace std;

int main()
{
    unsigned long long N, M;
    scanf("%llu %llu", &N, &M);
    
    if(N%2 == 1 && M%2 == 1)
        printf("%llu", (N * M - 1) / 2);
    else
        printf("%llu", N * M / 2);
    
    return 0;
}