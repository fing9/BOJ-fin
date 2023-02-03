#include <stdio.h>

int main(){
    int A, B, C, n, income;
    
    scanf("%d%d%d",&A,&B,&C);
    
    if(B >= C){
        printf("%d",-1);
        return 0;
    }
    
    income = C-B;
    
    printf("%d",(A/income)+1);
    
    return 0;
}