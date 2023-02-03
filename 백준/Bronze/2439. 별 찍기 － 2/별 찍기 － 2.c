#include <stdio.h>

int main(void)
{
    int N, i, j, k;
    
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        for(k=N;k>i;k--){
            printf(" ");
        }
        for(j=0;j<i;j++){
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}