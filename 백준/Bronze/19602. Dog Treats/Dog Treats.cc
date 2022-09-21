#include <iostream>

using namespace std;

int main() {
    int S, M, L, ret;
    scanf("%d\n%d\n%d", &S, &M, &L);
    
    ret = S + (2 * M) + (3 * L);
    
    if(ret >= 10) printf("happy");
    else printf("sad");
    
    return 0;
}