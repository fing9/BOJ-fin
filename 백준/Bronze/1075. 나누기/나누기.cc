#include <iostream>

using namespace std;

int main() {
    int N, F, last;
    
    scanf("%d\n%d", &N, &F);
    last = N % 100;
    N -= last;
    
    for(int i=0;i<100;i++) {
        last = (N+i) % 100;
        if((N+i) % F == 0) {
            break;
        }
    }
    
    if(last == 0) {
        printf("00");
    }
    else if(last < 10) {
        printf("0%d", last);
    }
    else {
        printf("%d", last);
    }
    
    
    return 0;
}