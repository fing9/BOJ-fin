#include <stdio.h>

int main(){
    int N, X, Y, shell = 1, sum;
    
    scanf("%d",&N); //수 입력
    
    while(shell<N){ //shell의 깊이를 측정, shell에서 몇 번째 cell인지를 구함
        N -= shell;
        shell += 1;
    }
    
    X = shell - N + 1; //cell의 두 항을 구함
    Y = N;
    
    if(shell % 2 == 1){ //깊이가 홀수일 때와 짝수일 때를 구분
        printf("%d/%d",X,Y);
    }
    else{
        printf("%d/%d",Y,X);
    }
    
    return 0;
}