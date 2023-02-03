#include <stdio.h>

int main(){
    int R, T, i, j, q;
    char S[200];
    
    scanf("%d",&T);
    for(i=0;i<T;i++){
        j = 0;
        scanf("%d %s",&R,S);
        while(S[j] != NULL){
            for(q=0;q<R;q++){
                printf("%c",S[j]);
            }
            j += 1;
        }
        printf("\n");
        for(q=0;q<200;q++){//초기화
            S[q] = NULL;
        }
    }
    
    return 0;
}