#include <iostream>

using namespace std;

int main() {
    int N;
    int a;
    char c;
    scanf("%d", &N);
    
    for(int i=0;i<N;i++) {
        scanf("%d %c", &a, &c);
        for(int j=0;j<a;j++) {
            printf("%c", c);
        }
        printf("\n");
    }
    
    return 0;
}