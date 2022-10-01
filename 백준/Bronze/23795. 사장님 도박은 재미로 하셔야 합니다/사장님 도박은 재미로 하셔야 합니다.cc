#include <iostream>

using namespace std;

int main() {
    long long sum = 0, inp;
    
    do {
        scanf("%lld", &inp);
        sum += inp;
    } while(inp != -1);
    if(sum != -1) sum++;
    
    printf("%lld", sum);
    
    return 0;
}