#include <stdio.h>

int main(){
    char A[3], B[3];
    int a = 0, b = 0, i;
    
    scanf("%s %s",A,B); //숫자 입력
    
    for(i=2;i>=0;i--){ //숫자 뒤집기
        if(i == 2){
            a += (A[i] - 48) * 100;
        }
        else if(i == 1){
            a += (A[i] - 48) * 10;
        }
        else{
            a += (A[i] - 48);
        }
    }

    for(i=2;i>=0;i--){ //숫자 뒤집기
        if(i == 2){
            b += (B[i] - 48) * 100;
        }
        else if(i == 1){
            b += (B[i] - 48) * 10;
        }
        else{
            b += (B[i] - 48);
        }
    }
    
    if(a > b){ //뒤집은 숫자 대소판별 후 출력
        printf("%d",a);
    }
    else{
        printf("%d",b);
    }
    
    return 0;
}