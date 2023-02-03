#include <stdio.h>

int main()
{
    int i, N;
    double M = 0.0;
    double avr = 0.0;
    
    scanf("%d",&N);
    
    double score[N];
    
    for(i=0;i<N;i++){
        scanf("%lf",&score[i]);
    }
    
    for(i=0;i<N;i++){
        if(score[i]>M){
            M = score[i];
        }
    }
    
    for(i=0;i<N;i++){
        avr += ((score[i]/M)*100);
    }
    
    printf("%0.2lf", avr/N);
    
    return 0;
}