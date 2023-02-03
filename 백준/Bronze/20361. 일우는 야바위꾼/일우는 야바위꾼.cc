#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int cups[200002]={0,};
    int N, X, K, tmp;
    scanf("%d %d %d",&N,&X,&K);
    cups[X]=1;
    for(int i=0;i<K;i++) {
        int a, b;
        scanf("%d %d",&a,&b);
        if(a==X || b==X) {
            tmp=cups[a];
            cups[a]=cups[b];
            cups[b]=tmp;
            if(cups[a]==1) X=a;
            else X=b;
        }
    }
    
    printf("%d",X);
    return 0;
}