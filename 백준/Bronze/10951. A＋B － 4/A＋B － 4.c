#include <stdio.h>

int main()
{
    int A, B;
    
    while(scanf("%d%d",&A,&B) != EOF){
        printf("%d",A+B);
        printf("\n");
    }
    
    return 0;
}