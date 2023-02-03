#include <iostream>

using namespace std;

int main() {
    int N, sum = 1;
    scanf("%d", &N);
    
    for(int i=0;i<N;i++) {
        int d;
        scanf("%d", &d);
        sum += d - 1;
    }
    
    printf("%d", sum);
    
    return 0;
}