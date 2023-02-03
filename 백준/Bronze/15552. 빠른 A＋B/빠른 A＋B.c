#include <stdio.h>

int main(void)
{
    int A, B, T, i;
    
    scanf("%d",&T);
    
    for(i=0;i<T;i++){
        scanf("%d%d",&A,&B);
        printf("%d",A+B);
        printf("\n");
    }
    
    return 0;
}