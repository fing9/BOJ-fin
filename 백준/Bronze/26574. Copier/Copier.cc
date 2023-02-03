#include <iostream>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    
    for(int i=0;i<n;i++) {
        int a, b;
        scanf("%d", &a);
        b = a;
        printf("%d %d\n", a, b);
    }
    
    return 0;
}