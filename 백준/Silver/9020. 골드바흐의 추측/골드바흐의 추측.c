#include <stdio.h>

int main(){
    int Eratos[10001], i, j, k, T, n, mid, answer;
    
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
    
    scanf("%d",&T);
    
    for(i=0;i<T;i++){
        scanf("%d",&n);
        mid = n/2;
        for(j=mid;j>=2;j--){
            if(Eratos[j] != 0 && Eratos[n-Eratos[j]] != 0){
                answer = j;
                j = 1;
            }
        }
        printf("%d %d\n",answer,n-answer);
    }
    
    return 0;
}