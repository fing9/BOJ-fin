# include <stdio.h>

int main()
{
    int N, i, j, k;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        for(k=i;k>0;k--)
        {
            printf(" ");
        }
        for(j=N-i-1;j>=0;j--)
        {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}