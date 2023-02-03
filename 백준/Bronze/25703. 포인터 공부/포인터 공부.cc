#include <iostream>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    
    printf("int a;\n");
    for(int i=1;i<=N;i++) {
        printf("int ");
        for(int j=0;j<i;j++) {
            printf("*");
        }
        
        printf("ptr");
        if(i != 1) {
            printf("%d", i); 
            if(i == 2)
                printf(" = &ptr;\n");
            else
                printf(" = &ptr%d;\n", i-1);
        }
        else
            printf(" = &a;\n");
    }
    
    return 0;
}