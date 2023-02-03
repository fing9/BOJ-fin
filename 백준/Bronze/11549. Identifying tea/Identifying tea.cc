#include <iostream>

using namespace std;

int main() {
    int T, A, B, C, D, E, ret = 0;
    
    scanf("%d\n%d %d %d %d %d", &T, &A, &B, &C, &D, &E);
    
    if(T == A) ret++;
    if(T == B) ret++;
    if(T == C) ret++;
    if(T == D) ret++;
    if(T == E) ret++;
    
    printf("%d", ret);
    
    return 0;
}