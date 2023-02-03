# include <stdio.h>

int main(){
    int N, i, j, rank;
    scanf("%d",&N);
    int paohoo[N][2];
    for(i=0;i<N;i++){
        scanf("%d %d",&paohoo[i][0],&paohoo[i][1]);
    }
    for(i=0;i<N;i++){
        rank = 0;
        for(j=0;j<N;j++){
            if(i!=j && paohoo[i][0]>paohoo[j][0] && paohoo[i][1]>paohoo[j][1]){
                rank++;
            }
            else if(i!=j && (paohoo[i][0]>=paohoo[j][0] || paohoo[i][1]>=paohoo[j][1])){
                rank++;
            }
        }
        printf("%d ",N-rank);
    }
    return 0;
}