# include <stdio.h>
# include <string.h>
int Na, Ma, Nb, Mb;
int A[101][101], B[101][101], C[101][101];

int main()
{
    int i, j, l, k;
    for(i=0;i<101;i++)
    {
        memset(A[i],0,sizeof(A[i]));
        memset(B[i],0,sizeof(B[i]));
        memset(C[i],0,sizeof(C[i]));
    }
    
    scanf("%d %d",&Na,&Ma); // input A
    for(i=1;i<=Na;i++)
    {
        for(j=1;j<=Ma;j++)
            scanf("%d",&A[i][j]);
    }
    
    scanf("%d %d",&Nb,&Mb); // input B
    for(i=1;i<=Nb;i++)
    {
        for(j=1;j<=Mb;j++)
            scanf("%d",&B[i][j]);
    }
    
    for(i=1;i<=Na;i++) // solve
    {
        for(j=1;j<=Mb;j++)
        {
            for(k=1;k<=Ma;k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    for(i=1;i<=Na;i++) // print
    {
        for(j=1;j<=Mb;j++)
        {
            printf("%d ",C[i][j]);
        }
        if(i!=Na)
            printf("\n");
    }
    
    return 0;
}