#include <iostream>
using namespace std;

int main()
{
    double A, B, C;
    scanf("%lf %lf %lf", &A, &B, &C);
    
    printf("%d", (int)max(A*B/C, A/B*C));
    
    return 0;
}