#include <iostream>

using namespace std;

int main() {
    int T;
    
    scanf("%d", &T);
    while(T--) {
        int N, AB, CD, ret;
        scanf("%d", &N);
        AB = N / 100;
        CD = N % 100;
        
        AB = AB * AB;
        CD = CD * CD;
        ret = AB + CD;
        
        if(ret % 7 == 1) printf("YES\n");
        else printf("NO\n");
    }
    
    return 0;
}