#include <stdio.h>

int main()
{
    int A, B, T, i;
    
    scanf("%d",&T);
    
    for(i=1;i<=T;i++){
        scanf("%d%d",&A,&B);
        printf("Case #%d: %d + %d = %d",i,A,B,A+B);
        printf("\n");
    }
    
    return 0;
}