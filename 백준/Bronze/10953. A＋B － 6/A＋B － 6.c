# include <stdio.h>

int main()
{
    int N, i, A, B;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%d,%d",&A,&B);
        printf("%d",A+B);
        if(i!=N-1)
            printf("\n");
    }
    return 0;
}