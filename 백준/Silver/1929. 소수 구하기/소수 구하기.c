#include <stdio.h>

int main(){
    int Eratos[1000001], i, j, k, M, N;
    
    for(i=2;i<1000001;i++){ //소수구하기
        Eratos[i]=i;
    }
    for(i=2;i<1000001;i++){
        if(Eratos[i] != 0){
            k = 2;
            for(j=i*k;j<1000001;j=i*k){
                Eratos[j] = 0;
                k += 1;
            }
        }
    }
    
    scanf("%d %d",&M,&N);
    
    for(j=M;j<=N;j++){
        if(Eratos[j] != 0){
            printf("%d\n",Eratos[j]);
        }
    }
    
    return 0;
}