#include <iostream>

using namespace std;

int main() {
    int x, y;
    int a, b, c, d, q, r;
    int ret, ret1, ret2;
    
    cin >> x >> y;
    a = 100 - x;
    b = 100 - y;
    c = 100 - a - b;
    d = a * b;
    q = d / 100;
    r = d % 100;
    
    ret = d;
    ret += c * 100;
    ret1 = ret % 100;
    ret /= 100;
    ret2 = ret % 100;
    
    printf("%d %d %d %d %d %d\n%d %d", a, b, c, d, q, r, ret2, ret1);
    
    return 0;
}