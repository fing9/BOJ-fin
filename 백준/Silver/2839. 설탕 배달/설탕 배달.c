#include <stdio.h>

int main(){
    int N, Num, judge;
    
    scanf("%d",&N);
    
    Num = N / 5;
    judge = N % 5;
    
    switch(judge){
        case 0:
            printf("%d",Num);
            break;
        case 1:
            Num += 1;
            printf("%d",Num);
            break;
        case 2:
            if(Num-1 <= 0){
                printf("%d",-1);
                break;
            }
            else{
                Num += 2;
                printf("%d",Num);
                break;
            }
        case 3:
            Num += 1;
            printf("%d",Num);
            break;
        case 4:
            if(Num-1 < 0){
                printf("%d",-1);
                break;
            }
            else{
                Num += 2;
                printf("%d",Num);
                break;
            }
    }
    return 0;
}