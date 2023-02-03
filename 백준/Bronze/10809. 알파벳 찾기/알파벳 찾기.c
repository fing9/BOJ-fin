#include <stdio.h>

int main(){
    char S[500];
    int i = 0 ,answer[26] = {0,};
    
    for(i=0;i<26;i++){
        answer[i] = -1;
    }
    
    i = 0;
    
    scanf("%s",S);
    
    while(S[i] != NULL){
        if(answer[(int)S[i]-97] == -1){
            answer[(int)S[i]-97] = i;
        }
        i += 1;
    }
    
    for(i=0;i<26;i++){
        if(answer[i] == -1){
            printf("%d",-1);
        }
        else{
            printf("%d",answer[i]);
        }
        if(i != 25){
            printf(" ");
        }
    }
    
    return 0;
}