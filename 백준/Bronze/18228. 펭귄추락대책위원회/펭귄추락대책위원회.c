# include <stdio.h>

int main()
{
    int N, A[200001], i, left=1000000000, right=1000000000, ispeng;
    
    scanf("%d",&N);
    
    for(i=1;i<=N;i++){
        scanf("%d",&A[i]);
        if(A[i]==-1)
            ispeng=i;
    }
    
    for(i=ispeng+1;i<=N;i++){
        if(A[i]<right)
            right=A[i];
    }
    for(i=ispeng-1;i>=1;i--){
        if(A[i]<left)
            left=A[i];
    }
    
    printf("%d",left+right);
    
    return 0;
}