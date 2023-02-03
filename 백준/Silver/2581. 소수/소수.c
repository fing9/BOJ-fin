#include <stdio.h>

int main(){
    int Eratos[10001], i, j, k, M, N, Num[10001], answer=0, sum=0, lowerestNum = 0;
    
    for(i=2;i<10001;i++){ //소수구하기
        Eratos[i]=i;
    }
    for(i=2;i<10001;i++){
        if(Eratos[i] != 0){
            k = 2;
            for(j=i*k;j<10001;j=i*k){
                Eratos[j] = 0;
                k += 1;
            }
        }
    }
    
    scanf("%d",&M);
    scanf("%d",&N);
    
    for(j=M;j<=N;j++){
        Num[j] = j;
    }
    for(j=M;j<=N;j++){
        if(Eratos[Num[j]] != 0){
            answer += 1;
            sum += Num[j];
            if(lowerestNum == 0){
                lowerestNum = Num[j];
            }
        }
    }
    
    if(answer != 0){
        printf("%d\n",sum);
        printf("%d",lowerestNum);
    }
    else{
        printf("-1");
    }
    
    return 0;
}