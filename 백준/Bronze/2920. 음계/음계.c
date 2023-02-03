#include <stdio.h>

int main()
{
    int Code[8], Pure[8] = {1,2,3,4,5,6,7,8}, i, judge = 0, des = 0;
    
    for(i=0;i<8;i++){
        scanf("%d",&Code[i]);
        if(Code[i] == Pure[i]){
            judge += 1;
        }
        else if(Code[i] == Pure[7-i]){
            des += 1;
        }
    }
    
    if(judge == 8){
        printf("ascending");
    }
    else if(des == 8){
        printf("descending");
    }
    else
        printf("mixed");
    
    return 0;
}