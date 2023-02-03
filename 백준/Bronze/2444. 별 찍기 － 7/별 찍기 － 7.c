# include <stdio.h>

int main()
{
    int N, i, j, star=1, space=1;
    scanf("%d",&N);
    for(i=0;i<2*N-1;i++)
    {
        for(j=0;j<N-space;j++)
        {
            printf(" ");
        }
        for(j=0;j<star;j++)
        {
            printf("*");
        }
        if(i!=2*N-2)
            printf("\n");
        if(i<N-1)
        {
            star+=2;
            space+=1;
        }
        else
        {
            star-=2;
            space-=1;
        }
    }
    return 0;
}