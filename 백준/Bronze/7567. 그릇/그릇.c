#include <stdio.h>

int main(){
    int height = 10, i = 0;
    char bowl[100];
    
    scanf("%s",bowl);
    
    while(bowl[i] != 0){
        if(bowl[i] == bowl[i+1]){
            height += 5;
        }
        else if(bowl[i] != bowl[i+1] && bowl[i+1] != 0){
            height += 10;
        }
        i += 1;
    }
    
    printf("%d",height);
    
    return 0;
}