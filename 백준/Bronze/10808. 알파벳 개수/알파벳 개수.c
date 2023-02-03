#include <stdio.h>

int main(){
    char S[500];
    int i=0, answer[26]={0,};
    
    scanf("%s",S);
    
    while(S[i] != NULL)
    {
        answer[(int)S[i]-97] += 1;
        i+=1;
    }
    
    for(i=0;i<26;i++)
    {
        printf("%d",answer[i]);
        if(i != 25)
            printf(" ");
    }
    
    return 0;
}