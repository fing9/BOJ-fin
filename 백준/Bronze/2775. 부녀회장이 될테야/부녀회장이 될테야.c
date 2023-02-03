#include <stdio.h>

int main(){
    int T, Y, n, i, j, k, HW[15][15] = {0,};
    
    for(i=1;i<15;i++){ // 미리구해놓은 거수민 수
        HW[0][i] = i;
    }
    for(i=1;i<15;i++){
        for(j=1;j<15;j++){
            for(k=1;k<=j;k++){
                HW[i][j] += HW[i-1][k];
            }
        }
    }
    
    scanf("%d",&T);
    
    for(i=0;i<T;i++){ // 호실 검색
        scanf("%d",&Y);
        scanf("%d",&n);
        printf("%d\n",HW[Y][n]);
    }
    
    return 0;
}