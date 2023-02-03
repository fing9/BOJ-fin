#include <stdio.h>

int main()
{
    int A, B, C, S, i, k, D[10] = {0,0,0,0,0,0,0,0,0,0};
    
    scanf("%d",&A);
    scanf("%d",&B);
    scanf("%d",&C);
    
    S = A * B * C;
    
    while(S>0){
        k = S % 10;
        D[k] += 1;
        S = S / 10;
    }
    
    for(i=0;i<10;i++){
        printf("%d\n",D[i]);
    }
    
    return 0;
}