#include <iostream>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    
    while(n > 0) {
        if(n >= 5) {
            printf("V");
            n -= 5;
        }
        else {
            printf("I");
            n -= 1;
        }
    }
    
    return 0;
}