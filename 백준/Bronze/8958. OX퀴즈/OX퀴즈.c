#include <stdio.h>

int main()
{
    int i, j, N, cont, score = 0;
    char cases[81];
    scanf("%d",&N);
    
    for(i=0;i<N;i++){
        scanf("%s", cases);
        cont = 1;
        for(j=0;cases[j]!=NULL;j++){
            if(cases[j] == 'O'){
                score += cont;
                cont += 1;
            }
            else{
                cont = 1;
            }
        }
        printf("%d\n",score);
        score = 0;
    }
    return 0;
}