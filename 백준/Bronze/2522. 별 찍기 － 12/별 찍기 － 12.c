# include <stdio.h>

int main()
{
    int N, i, j, star=1, space;
    scanf("%d",&N);
    space = N-1;
    for(i=0;i<(2*N);i++)
    {
        for(j=0;j<space;j++)
            printf(" ");
        for(j=0;j<star;j++)
            printf("*");
        
        if(i==(2*N)-2)
            return 0;
        else
            printf("\n");
        if(i<N-1)
        {
            star++;
            space--;
        }
        else
        {
            star--;
            space++;
        }
    }
    return 0;
}