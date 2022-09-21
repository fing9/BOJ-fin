#include <stdio.h>

int main(){
    int N, M, i, j, k, answer = 0;
    scanf("%d %d",&N,&M);
    int card[N];
    for(i=0;i<N;i++){
        scanf("%d",&card[i]);
    }
    for(i=0;i<N;i++){
        for(j=i+1;j<N;j++){
            for(k=j+1;k<N;k++){
                if((card[i]+card[j]+card[k])>=answer && (card[i]+card[j]+card[k])<=M){
                    answer = card[i]+card[j]+card[k];
                }
            }
        }
    }
    printf("%d",answer);
    return 0;
}