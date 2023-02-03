#include <iostream>

using namespace std;

int main() {
    int N, now = 1, cnt = 0;
    
    scanf("%d", &N);
    
    while(N > 0) {
        if(N >= now){
            N -= now;
            now++;
            cnt++;
        }
        else {
            now = 1;
        }
    }
    
    printf("%d", cnt);
    
    return 0;
}