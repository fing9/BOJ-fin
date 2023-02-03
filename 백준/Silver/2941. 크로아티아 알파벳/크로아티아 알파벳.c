#include <stdio.h>

int main(){
    int i = 0, answer = 0;
    char str[300];
    
    scanf("%s",str);
    
    while(str[i] != 0){
        if(str[i] == 99 && (str[i+1] == 45 || str[i+1] == 61)){
            i += 1;
        }
        else if(str[i] == 100 && (str[i+1] == 45 || (str[i+1] == 122 && str[i+2] == 61))){
            if(str[i+2] == 61){
                i += 2;
            }
            else{
                i += 1;
            }
        }
        else if(str[i] == 108 && str[i+1] == 106){
            i += 1;
        }
        else if(str[i] == 110 && str[i+1] == 106){
            i += 1;
        }
        else if(str[i] == 115 && str[i+1] == 61){
            i += 1;
        }
        else if(str[i] == 122 && str[i+1] == 61){
            i += 1;
        }
        answer += 1;
        i += 1;
    }
    
    printf("%d",answer);
    
    return 0;
}