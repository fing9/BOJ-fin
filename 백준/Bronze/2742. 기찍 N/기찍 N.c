#include <stdio.h>

int main(void)
{
    int N, i;
    
    scanf("%d",&N);
    
    for(i=N;i>=1;i--){
        printf("%d",i);
        printf("\n");
    }
    
    return 0;
}