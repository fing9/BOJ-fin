# include <stdio.h>

int  main()
{
    int N, star=0, i, j;
    scanf("%d",&N);
    
    for(i=1;i<=N;i++){
        star++;
        for(j=0;j<star;j++){
            printf("*");
        }
        if(N!=1)
            printf("\n");
    }
    for(i=1;i<N;i++){
        star--;
        for(j=0;j<star;j++){
            printf("*");
        }
        if(i!=N-1)
            printf("\n");
    }
    return 0;
}