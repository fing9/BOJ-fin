#include <iostream>

using namespace std;

int main()
{
    int m=0, s=0, n;
    
    scanf("%d", &n);
    s += n;
    scanf("%d", &n);
    s += n;
    scanf("%d", &n);
    s += n;
    scanf("%d", &n);
    s += n;
    
    m = s/60;
    s %= 60;
    
    printf("%d\n%d", m, s);
    
    return 0;
}