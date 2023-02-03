# include <stdio.h>

int main()
{
    int N, i, j, space=0, star;
    scanf("%d",&N);
    star=(N*2)-1;
    
    for(i=0;i<(N*2)-1;i++)
    {
        if(i<N-1)
        {
            for(j=0;j<space;j++)
                printf(" ");
            space++;
            for(j=0;j<star;j++)
                printf("*");
            star -=2;
            printf("\n");
        }
        else
        {
            for(j=0;j<space;j++)
                printf(" ");
            space--;
            for(j=0;j<star;j++)
                printf("*");
            star +=2;
            if(i!=(N*2)-2)
                printf("\n");
        }
    }
    return 0;
}