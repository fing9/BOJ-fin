#include <stdio.h>

int onenum(int n){ //한수니깐 onenum 엌ㅋㅋㅋㅋ;
    int judge[10] ={0,};
    int i = 1, j, isonenum = 1;
    
    judge[0] = n % 10;
    
    while(n>=10){ //judge배열에 숫자를 잘라서 넣기
        n /= 10;
        judge[i] = n % 10;
        i += 1;
    }
    
    if(i==1 || i==2){ //한자리 수나 두자리 수는 무조건 한수
        return 1;
    }
    
    for(j=0;j<i-2;j++){ //3자리 이상의 수가 등차수열을 이루는지 판별
        if((judge[j]-judge[j+1]) != (judge[j+1] - judge[j+2])){
            isonenum = 0;
        }
    }
    
    if(isonenum == 1){ //등차수열을 이룰경우 true, 아니면 false 반환
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int N, i, answer = 0;
    
    scanf("%d",&N);
    
    for(i=1;i<=N;i++){
        if(onenum(i) == 1){
            answer += 1;
        }
    }
    
    printf("%d",answer);
    
    return 0;
}