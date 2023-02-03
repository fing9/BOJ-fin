# include <stdio.h>

int main()
{
    int T, N, M, i, j;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d %d",&N,&M);
        if(N<12 || M<4)
        {
            if(i!=T-1)
                printf("-1\n");
            else
                printf("-1");
            continue;
        }
        else
        {
            if(i!=T-1)
                printf("%d\n",(11*M)+4);
            else
                printf("%d",(11*M)+4);
        }
    }
    return 0;
}