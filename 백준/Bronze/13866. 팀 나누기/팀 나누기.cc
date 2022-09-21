#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main() {
    int a, b, c, d;
    int ret = 1987654321;
    cin >> a >> b >> c >> d;
    
    ret = min(ret, abs(abs(a-b) - abs(c-d)));
    ret = min(ret, abs(abs(a-c) - abs(b-d)));
    ret = min(ret, abs(abs(a-d) - abs(c-b)));
    
    cout << ret;
    
    return 0;
}