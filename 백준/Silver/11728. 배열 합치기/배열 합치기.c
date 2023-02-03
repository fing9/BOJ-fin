# include <stdio.h>
# include <stdlib.h>
int A[1100000]={0,}, B[1100000]={0,}, C[2200000]={0,};
int N, M;

int main()
{
    int i, j, l=0;
    scanf("%d %d",&N,&M);
    for(i=0;i<N;i++)
        scanf("%d",&A[i]);
    for(i=0;i<M;i++)
        scanf("%d",&B[i]);
    
    i=0;
    j=0;
    while(i<N && j<M)
    {
        if(A[i]<=B[j])
            C[l++]=A[i++];
        else
            C[l++]=B[j++];
    }
    
    while(i<N)
        C[l++]=A[i++];
    while(j<M)
        C[l++]=B[j++];
    
    for(i=0;i<l;i++)
    {
        printf("%d ",C[i]);
    }
    
    return 0;
}