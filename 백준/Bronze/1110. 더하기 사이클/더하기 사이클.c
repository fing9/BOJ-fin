#include <stdio.h>

int main()
{
    int N, Cycle, Origin, Num_1, Num_2;
    
    Cycle = 1;
    
    scanf("%d",&N);
    
    Origin = N;
    
    Num_1 = N % 10; //1의자리
    Num_2 = (N - Num_1) / 10; //10의자리
    N = (Num_1 * 10) + ((Num_1 + Num_2) % 10); //새로운 수
    
    if (N == Origin){
        printf("%d",Cycle);
    }
    else{
        while(N != Origin){
            Num_1 = N % 10; //1의자리
            Num_2 = (N - Num_1) / 10; //10의자리
            N = (Num_1 * 10) + ((Num_1 + Num_2) % 10); //새로운 수
            Cycle += 1;
        }
        printf("%d",Cycle);
    }
    
    return 0;
}