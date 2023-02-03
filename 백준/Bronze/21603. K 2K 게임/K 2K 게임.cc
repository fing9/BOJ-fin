#include <iostream>

using namespace std;

int main() {
    int N, K, cnt = 0;
    
    scanf("%d %d", &N, &K);
    
    for(int i=1;i<=N;i++) {
        if((i % 10 != K % 10) && (i % 10 != (K * 2) % 10)) {
            cnt++;
        }
    }
    printf("%d\n", cnt);
    
    for(int i=1;i<=N;i++) {
        if((i % 10 != K % 10) && (i % 10 != (K * 2) % 10)) printf("%d ", i);
    }
    
    return 0;
}