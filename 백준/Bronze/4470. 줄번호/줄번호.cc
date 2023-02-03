#include <iostream>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    getchar();
    
    for(int i=1;i<=N;i++) {
        char c;
        printf("%d. ", i);
        while(1) {
            c = getchar();
            if(c == '\n') {
                printf("\n");
                break;
            }
            else if(c == EOF) break;
            else printf("%c", c);
        }
    }
    
    return 0;
}