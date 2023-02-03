#include <stdio.h>

int main(){
    int i = 0, answer = 0;
    char str[1000000];
    
    scanf("%[^\n]s",str);
    
    while(str[i] != 0){
        if(str[i] != 32 && str[i] != 0){
            while(str[i] != 32 && str[i] != 0){
                i += 1;
            }
            answer += 1;
        }
        else{
            i += 1;
        }
    }
    
    printf("%d",answer);
    
    return 0;
}