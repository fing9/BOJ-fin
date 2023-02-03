#include <stdio.h>

int main(){
    int N, i = 0, sum = 0;
    char Num[100];
    
    scanf("%d",&N);
    scanf("%s",Num);
    while(i<N){
        sum += (int)Num[i] - 48;
        i += 1;
    }
    
    printf("%d",sum);
    
    return 0;
}