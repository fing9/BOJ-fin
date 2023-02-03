#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int A, B, C;
    int New;
    
    scanf("%d %d",&A,&B);
    scanf("%d",&C);
    
    if(B+C<60) {
        printf("%d %d",A,B+C);
    }
    else if(B+C>=60) {
        A+=(B+C)/60;
        New=(B+C)%60;
        A%=24;
        printf("%d %d",A,New);
    }
    
    return 0;
}