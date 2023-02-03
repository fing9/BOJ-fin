#include <stdio.h>

int main(){
    int N, shell = 1, i = 1;
    
    scanf("%d",&N);
    
    if(N == 1){
        printf("%d",1);
        return 0;
    }
    
    N -= 1;
    
    while(N > 0){
        N -= 6 * i;
        if(N >= 0){
            shell += 1;
        }
        i += 1;
    }
    
    if(N == 0){
        printf("%d",shell);
    }
    else if(N < 0){
        printf("%d",shell+1);
    }
    
    return 0;
}