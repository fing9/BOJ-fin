#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N, cnt = 0;
    scanf("%d", &N);
    
    for(int i=1;i<=500;i++) {
        if(sqrt((double)(i * i) + N) == (int)sqrt((double)(i * i) + N)) cnt++;
    }
    
    printf("%d", cnt);
    
    return 0;
}