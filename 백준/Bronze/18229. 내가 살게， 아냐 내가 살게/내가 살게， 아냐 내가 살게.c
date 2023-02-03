# include <stdio.h>
# include <string.h>

int main()
{
    int N, M, K, i, j, answer1, answer2=10000, time=0;
    scanf("%d%d%d",&N,&M,&K);
    int A[N][M], sum[N][2];
    memset(A,0,sizeof(A));
    memset(sum,0,sizeof(sum));
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            sum[i][0]+=A[i][j];
            sum[i][1]+=1;
            if(sum[i][0]>=K && sum[i][1]<answer2){
                answer1=i+1;
                answer2=sum[i][1];
            }
        }
    }
    printf("%d %d",answer1,answer2);
    return 0;
}