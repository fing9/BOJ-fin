#include <stdio.h>

int main()
{
    int N, i, Max, Min;
    
    Max = -1000000;
    Min = 1000000;
    
    scanf("%d",&N);
    
    int Ar[N];
    
    for(i=0;i<N;i++){
        scanf("%d",&Ar[i]);
    }
    
    for(i=0;i<N;i++){
        if (Max<Ar[i]){
            Max = Ar[i];
        }
        if (Min>Ar[i]){
            Min = Ar[i];
        }
    }
    
    printf("%d %d",Min,Max);
    
    return 0;
}