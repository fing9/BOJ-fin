# include <stdio.h>

int main()
{
    int N, i, k;
    scanf("%d", &N);
    int star=1, space=(N-1)*2;
    
    for(i=0;i<(N*2)-1;i++)
    {
        for(k=0;k<star;k++)
            printf("*");
        for(k=0;k<space;k++)
            printf(" ");
        for(k=0;k<star;k++)
            printf("*");
        if(i<N-1)
        {
            star++;
            space-=2;
        }
        else
        {
            star--;
            space+=2;
        }
        if(i!=(N*2)-2)
            printf("\n");
    }
    
    return 0;
}