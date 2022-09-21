#include <stdio.h>

int main(void)
{
    int i, N;
    
    scanf("%d",&N);
    
    for(i=1;i<=9;i++){
        printf("%d * %d = %d\n",N,i,N*i);
    }
    
    return 0;
}