#include <iostream>

using namespace std;

int main() {
    int ret = 0;
    int a, b, c;
    int a2, b2, c2;
    
    cin >> a >> b >> c;
    cin >> a2 >> b2 >> c2;
    
    if(a<a2) ret += a2 - a;
    if(b<b2) ret += b2 - b;
    if(c<c2) ret += c2 - c;
    
    cout << ret;
    
    return 0;
}