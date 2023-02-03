# include <stdio.h>

int main()
{
    int N, i, j, space, star=1;
    scanf("%d",&N);
    space=N-1;
    for(i=0;i<N;i++)
    {
        for(j=0;j<space;j++)
            printf(" ");
        for(j=0;j<star;j++)
            printf("*");
        if(i!=N-1)
            printf("\n");
        star+=2;
        space--;
    }
    return 0;
}