# include <stdio.h>

int main(){
    int Num[1000], i=0, j, N, tmp;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&Num[i]);
    }
    
    for(i=0;i<N;i++){ //bubble sort
        for(j=i;j<N;j++){
            if(Num[i]>Num[j]){
                tmp = Num[i];
                Num[i] = Num[j];
                Num[j] = tmp;
            }
        }
    }
    
    for(i=0;i<N;i++){
        if(i!=N-1)
            printf("%d\n",Num[i]);
        else
            printf("%d",Num[i]);
    }
    
    return 0;
}