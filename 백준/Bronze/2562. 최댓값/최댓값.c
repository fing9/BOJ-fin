#include <stdio.h>

int main()
{
    int N[9], Max, i, Max_Num;
    Max = 0;
    
    for(i=0;i<9;i++){
        scanf("%d",&N[i]);
        if(Max<N[i]){
            Max = N[i];
            Max_Num = i+1;
        }
    }
    printf("%d",Max);
    printf("\n");
    printf("%d",Max_Num);
    
    return 0;
}