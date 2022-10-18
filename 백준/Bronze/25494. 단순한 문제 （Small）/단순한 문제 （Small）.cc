#include <iostream>

using namespace std;

int main() {
    int T;
    
    scanf("%d", &T);
    
    while(T--) {
        int a, b, c, cnt = 0;
        scanf("%d %d %d", &a, &b, &c);
        
        for(int i=1;i<=a;i++) {
            for(int j=1;j<=b;j++) {
                for(int k=1;k<=c;k++) {
                    if((i % j == j % k) && (j % k == k % i) && (i % j == k % i)) cnt++;
                }
            }
        }
        
        printf("%d\n", cnt);
    }
    
    return 0;
}