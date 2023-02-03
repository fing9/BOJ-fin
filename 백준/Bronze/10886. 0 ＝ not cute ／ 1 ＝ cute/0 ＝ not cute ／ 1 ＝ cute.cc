#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int N, num, cnt0=0, cnt1=0;
    scanf("%d",&N);
    for(int i=0;i<N;i++) {
        scanf("%d",&num);
        if(num==0) cnt0++;
        else cnt1++;
    }
    if(cnt0>cnt1) printf("Junhee is not cute!");
    else printf("Junhee is cute!");
    
    return 0;
}