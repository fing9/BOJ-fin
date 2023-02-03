# include <stdio.h>

int main()
{
    int N, i, j, k, space, nextspace=1;
    scanf("%d",&N);
    if(N%2 == 0)
    {
        printf("I LOVE CBNU");
        return 0;
    }
    for(i=0;i<N;i++)
    {
        printf("*");
    }
    printf("\n");
    space = N/2;
    for(i=0;i<=N/2;i++)
    {
        for(k=0;k<space;k++)
            printf(" ");
        space--;
        if(i!=0)
        {
            printf("*");
            for(k=0;k<nextspace;k++)
                printf(" ");
            printf("*");
            nextspace += 2;
        }
        else
            printf("*");
        if(i!=N/2)
            printf("\n");
    }
    
    return 0;
}