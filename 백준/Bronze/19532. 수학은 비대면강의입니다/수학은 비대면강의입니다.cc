#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d, e, f;
    int ae_bd, ce_bf, af_cd;
    int x, y;
    
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    
    ae_bd = (a*e) - (b*d);
    ce_bf = (c*e) - (b*f);
    af_cd = (a*f) - (c*d);
    
    x = ce_bf/ae_bd;
    y = af_cd/ae_bd;
    
    printf("%d %d", x, y);
    
    return 0;
}