#include <stdio.h>

int main(){
    int Eratos[300001], i, j, k, N, answer = 0;
    
    for(i=2;i<300001;i++){ //소수구하기
        Eratos[i]=i;
    }
    for(i=2;i<300001;i++){
        if(Eratos[i] != 0){
            k = 2;
            for(j=i*k;j<300001;j=i*k){
                Eratos[j] = 0;
                k += 1;
            }
        }
    }
    
    scanf("%d",&N);
    
    while(N != 0){ //체로거르기
        for(j=N+1;j<=2*N;j++){
            if(Eratos[j] != 0){
                answer++;
            }
        }
        printf("%d\n",answer);
        scanf("%d",&N);
        answer = 0;
    }
    
    return 0;
}