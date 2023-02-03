#include <iostream>

using namespace std;

int main() {
    int N, A, B, ret = 0;
    
    scanf("%d", &N);
    scanf("%d %d", &A, &B);
    
    while(N > 0 && (A > 1 || B > 0)) {
        ret++;
        N--;
        if(A > 1) A -= 2;
        else B--;
    }
    
    printf("%d", ret);
    
    return 0;
}