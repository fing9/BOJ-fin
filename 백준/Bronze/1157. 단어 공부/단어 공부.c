#include <stdio.h>

int main(){
    int i=0, j, answer, dab, A[26] = {0,};
    char str[1000000];
    
    scanf("%s",str);
    
    if(str[1] == NULL){ //한글자일 경우
        if((int)str[0] < 96){
            printf("%c",str[0]);
        }
        else{
            printf("%c",str[0]-32);
        }
        return 0;
    }
    
    while(str[i] != NULL){ //알파벳 갯수 새기
        if((int)str[i] < 96){
            A[(int)str[i]-65] += 1;
        }
        else{
            A[(int)str[i]-97] += 1;
        }
        i += 1;
    }
    
    answer = -1;
    
    for(i=0;i<26;i++){ //가장 빈번한 알파벳 찾아내기
        if(answer < A[i]){
            answer = A[i];
            dab = i;
        }
    }
    
    for(i=0;i<26;i++){ //동일한 최고등장횟수의 알파벳 유무판별
        if(A[dab] == A[i] && dab != i){
            answer = 1000001;
        }
    }
    
    if(answer != 1000001){ //가장 빈번한 알바벳 출력
        printf("%c",dab+65);
    }
    else{
        printf("?");
    }
    
    return 0;
}