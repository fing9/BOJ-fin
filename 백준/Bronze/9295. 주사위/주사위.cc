#include <iostream>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    
    for(int i=1;i<=N;i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("Case %d: %d\n", i, a+b);
    }
    
    return 0;
}