#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int day, N, ret=0;
    scanf("%d",&day);
    for(int i=0;i<5;i++) {
        scanf("%d",&N);
        if(N==day) ret++;
    }
    printf("%d",ret);
    
    return 0;
}