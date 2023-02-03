# include <stdio.h>

int main()
{
    int N, i, j;
    scanf("%d",&N);
    int space=N-1, level=1;
    
    for(i=0;i<N;i++)
    {
        for(j=0;j<space;j++)
            printf(" ");
        for(j=0;j<level;j++)
        {
            if(j%2 == 0)
                printf("*");
            else
                printf(" ");
        }
        level+=2;
        space-=1;
        if(i!=N-1)
            printf("\n");
    }
    
    return 0;
}