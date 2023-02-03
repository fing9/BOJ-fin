#include <stdio.h>

int main(void) 
{
    int a, b, b1, b2, b3;
    
    scanf("%d",&a);
    scanf("%d",&b);
    
    b1 = b % 10;
    b2 = ((b % 100) - b1) / 10;
    b3 = (b - b2 - b1) / 100;
    
    printf("%d",b1 * a);
    printf("\n");
    printf("%d",b2 * a);
    printf("\n");
    printf("%d",b3 * a);
    printf("\n");
    printf("%d",a * b);
    
    return 0;
}