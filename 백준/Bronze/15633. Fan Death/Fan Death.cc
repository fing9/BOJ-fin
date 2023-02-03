#include <iostream>

using namespace std;

int main() {
    int n = 0, sum = 0;
    scanf("%d", &n);
    
    for(int i=1;i<=n;i++) {
        if(n % i == 0) sum += i;
    }
    
    sum *= 5;
    sum -= 24;
    
    printf("%d", sum);
    
    return 0;
}