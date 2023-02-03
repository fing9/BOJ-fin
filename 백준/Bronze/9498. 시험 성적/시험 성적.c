#include <stdio.h>

int main(void)
{
    int k;
    
    scanf("%d",&k);
    
    if (k >= 90 && k <= 100)
        printf("A");
    else if (k >= 80 && k < 90)
        printf("B");
    else if (k >= 70 && k < 80)
        printf("C");
    else if (k >= 60 && k < 70)
        printf("D");
    else
        printf("F");
    
        
    return 0;
}