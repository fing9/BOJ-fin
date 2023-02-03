#include <stdio.h>

int main()
{
    int i, j, C, N, overavr = 0;
    int score[1000];
    double avr, answer[1000];
    
    scanf("%d",&C);
    
    for(i=0;i<C;i++){
        
        avr = 0.0;
        overavr = 0;
        
        scanf("%d",&N);
        for(j=0;j<N;j++){
            scanf("%d",&score[j]);
        }
        for(j=0;j<N;j++){
            avr += (double)score[j];
        }
        avr /= (double)N;
        for(j=0;j<N;j++){
            if(avr < score[j]){
                overavr += 1;
            }
        }
        answer[i] = (double)overavr*100/(double)N;
    }
    
    for(i=0;i<C;i++){
        printf("%.3lf%%\n",answer[i]);
    }
    
    return 0;
}