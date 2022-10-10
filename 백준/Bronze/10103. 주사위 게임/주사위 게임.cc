#include <iostream>

using namespace std;

int main() {
    int n, score1 = 100, score2 = 100;
    scanf("%d", &n);
    
    for(int i=0;i<n;i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        
        if(a < b) score1 -= b;
        else if(a > b) score2 -= a;
    }
    
    printf("%d\n%d", score1, score2);
    
    return 0;
}