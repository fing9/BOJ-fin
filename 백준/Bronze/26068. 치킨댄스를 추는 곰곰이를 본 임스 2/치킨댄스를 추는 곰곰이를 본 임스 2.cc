#include <iostream>

using namespace std;

int main() {
    int n, ret = 0;
    int inp;
    
    scanf("%d", &n);
    while(n--) {
        scanf("%*c%*c%*c%d", &inp);
        if(inp<=90) ret++;
    }
    
    printf("%d", ret);
    
    return 0;
}