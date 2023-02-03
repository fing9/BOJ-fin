# include <stdio.h>

int main()
{
    int N, i, j;
    
    scanf("%d",&N);
    
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
        {
            if(j%2==1 && j==1)
                printf("*");
            else if(j%2==1)
                printf(" *");
        }
        if(N!=1)
            printf("\n");
        for(j=1;j<=N;j++)
        {
            if(j%2==0)
                printf(" *");
        }
        if(i!=N)
            printf("\n");
    }
    
    return 0;
}