#include <stdio.h>

int main()
{
    int A, B, i;
    
    scanf("%d%d",&A,&B);
    while(A+B != 0){
        printf("%d",A+B);
        printf("\n");
        scanf("%d%d",&A,&B);
    }
    return 0;
}