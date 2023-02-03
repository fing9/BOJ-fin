#include <stdio.h>

int main(void)
{
    int A, B;
    
    scanf("%d%d",&A,&B);
    
    if (A>B)
        printf(">");
    else if (A<B)
        printf("<");
    else
        printf("==");
    
    return 0;
}