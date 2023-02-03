#include <stdio.h>

int main(){
    int Eratos[1001], i, j, k, N, Num, answer=0;
    
    for(i=2;i<1001;i++){ //소수구하기
        Eratos[i]=i;
    }
    for(i=2;i<1001;i++){
        if(Eratos[i] != 0){
            k = 2;
            for(j=i*k;j<1001;j=i*k){
                Eratos[j] = 0;
                k += 1;
            }
        }
    }
    
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&Num);
        if(Eratos[Num] != 0){
            answer++;
        }
    }
    
    printf("%d",answer);
    
    return 0;
}