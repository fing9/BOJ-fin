#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    unsigned long long ull;
    double d, ret;
    
    scanf("%llu", &ull);
    
    d = sqrt(ull);
    printf("%.8lf", d * 4);
    
    return 0;
}