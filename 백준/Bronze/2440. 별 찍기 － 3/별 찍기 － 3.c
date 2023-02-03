# include <stdio.h>

int main()
{
    int N, i, j;
    scanf("%d",&N);
    for(i=1;i<=N;i++)
    {
        for(j=N-i;j>=0;j--)
        {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}