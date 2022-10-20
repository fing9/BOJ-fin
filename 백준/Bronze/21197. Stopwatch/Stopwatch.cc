#include <iostream>

using namespace std;

int main() {
    int N, ret = 0, last = 0;
    scanf("%d", &N);
    
    if(N%2 == 1) {
        printf("still running");
        return 0;
    }
    
    for(int i=1;i<=N;i++) {
        int t;
        scanf("%d", &t);
        
        if(i % 2 == 0) ret += t - last;
        last = t;
    }
    
    printf("%d", ret);
    
    return 0;
}