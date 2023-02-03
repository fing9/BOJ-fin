#include <stdio.h>

int main(void)
{
    int A, B, C, ex;
    
    scanf("%d%d%d", &A, &B ,&C);

    if (A > B){
        ex = A;
        A = B;
        B = ex;
    }
    if (B > C){
        ex = B;
        B = C;
        C = ex;
    }
    if (A > B){
        ex = A;
        A = B;
        B = ex;
    }
        
    printf("%d",B);
    
    return 0;
}