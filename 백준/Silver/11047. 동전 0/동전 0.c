#include <stdio.h>

int main(){
    int N, K, i, itwas=0, count = 0;
    
    scanf("%d %d",&N,&K);
    int coin[N];
    for(i=N-1;i>=0;i--){
        scanf("%d",&coin[i]);
    }
    
    while(K!=0){
        for(i=itwas;i<N;i++){
            if(coin[i]<=K){
                count += K/coin[i];
                K %= coin[i];
                itwas = i + 1;
            }
        }
    }
    
    printf("%d",count);
    
    return 0;
}