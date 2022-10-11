#include <iostream>

using namespace std;

int main() {
    int e, f, c, tmp, ret = 0;
    scanf("%d %d %d", &e, &f, &c);
    e += f;
    
    while(e > 0) {
        tmp = e / c;
        if(tmp == 0) break;
        e %= c;
        e += tmp;
        ret += tmp;
    }
    
    printf("%d", ret);
    
    return 0;
}