#include <iostream>

using namespace std;

int main() {
    long long N, S;
    
    while(scanf("%lld %lld", &N, &S) != EOF) {
        printf("%lld\n", S / (N + 1));
    }
    
    return 0;
}