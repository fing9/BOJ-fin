#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, h, v;
    int a, b, c, d;
    
    scanf("%d %d %d", &n, &h, &v);
    
    a = abs(n-h) * abs(n-v) * 4;
    b = abs(n-h) * v * 4;
    c = h * abs(n-v) * 4;
    d = h * v * 4;
    
    printf("%d", max(max(a,b),max(c,d)));
    
    return 0;
}