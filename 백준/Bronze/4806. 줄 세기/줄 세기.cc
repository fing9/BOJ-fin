#include <iostream>

using namespace std;

int main() {
    char c;
    int cnt = 0;
    
    while(scanf("%c", &c) > 0) {
        if(c == '\n') cnt++;
    }
    
    printf("%d", cnt);
    
    return 0;
}