# include <stdio.h>

int main()
{
    int N, M;
    scanf("%d %d",&N,&M);
    if(N>=M)
        printf("%d",(N)*(M-1)+N-1);
    else
        printf("%d",(M)*(N-1)+M-1);
    return 0;
}