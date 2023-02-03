#include <stdio.h>

int main(void)
{
    int H, M, reM;
    reM = 0;
    
    scanf("%d%d",&H,&M);
    
    if (M < 45 && H != 0){
        reM = 15 + M;
        H -= 1;
    }
    else if (M < 45 && H == 0){
        reM = 15 + M;
        H = 23;
    }
    else
        reM = M - 45;
    
    printf("%d %d", H, reM);
    
    return 0;
}