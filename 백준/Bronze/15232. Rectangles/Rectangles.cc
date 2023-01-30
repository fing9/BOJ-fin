#include <iostream>

using namespace std;

int main() {
    int R, C;
    scanf("%d\n%d", &R, &C);
    
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}