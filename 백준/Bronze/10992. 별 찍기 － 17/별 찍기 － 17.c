# include <stdio.h>

int main()
{
    int N, i, j;
    scanf("%d",&N);
    int space_outside=N-1, space_inside=1;
    
    for(i=0;i<N;i++)
    {
        if(i==0)
        {
            for(j=0;j<space_outside;j++)
                printf(" ");
            printf("*");
            space_outside--;
            if(N!=1)
                printf("\n");
        }
        else if(i!=N-1)
        {
            for(j=0;j<space_outside;j++)
                printf(" ");
            printf("*");
            for(j=0;j<space_inside;j++)
                printf(" ");
            printf("*");
            space_outside--;
            space_inside+=2;
            printf("\n");
        }
        else
        {
            for(j=0;j<(N*2)-1;j++)
                printf("*");
        }
    }
    
    return 0;
}