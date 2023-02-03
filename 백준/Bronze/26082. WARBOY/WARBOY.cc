#include <iostream>

using namespace std;

int main() {
    int a, b, c, ret;
    scanf("%d %d %d", &a, &b, &c);
    
    ret = (b / a) * 3 * c;
    
    printf("%d", ret);
    
    return 0;
}