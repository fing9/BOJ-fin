# include <stdio.h>

int main()
{
    int N, M, K, team=0;
    scanf("%d %d %d",&N,&M,&K);
    
    while(N+M>=K+3 && N>=2 && M>=1)
    {
        N-=2;
        M-=1;
        team++;
    }
    printf("%d",team);
    return 0;
}