#include <stdio.h>

int judge(char str[]){
    int i = 0, j = 0, N = 0, judge = 1;
    int apb[26] = {0,};
    
    while(str[i] != 0){
        N += 1;
        i += 1;
    }
    
    if(N <= 2){ //1,2자리수의 수는 무조건 그룹 단어.
        return 1;
    }
    
    for(i=0;i<N;i++){ //각 알파벳의 갯수 새기
        apb[str[i]-97] += 1;
    }
    
    i = 0;
    while(i < N){
        while(j + 1 < N){ //이어지지 않는 알파벳이 있는지 판별
            if(str[i] == str[j] && str[j] == str[j+1]){
                judge += 1;
            }
            j += 1;
        }
        if(apb[str[i]-97] != judge){ //이어지는 알파벳의 갯수와 전체 알파벳의 갯수가 일치하는지 확인
            return 2;
        }
        i += 1;
        j = 0;
        judge = 1;
    }
    
    return 1;
}

int main(){
    int i = 0, N, answer = 0;
    char str[150];
    
    scanf("%d",&N);
    
    for(i=0;i<N;i++){
        scanf("%s",str);
        if(judge(str) == 1){
            answer += 1;
        }
    }
    
    printf("%d",answer);
    
    return 0;
}