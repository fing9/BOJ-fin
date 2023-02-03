# include <stdio.h>
int N, M, l=0;
int stack[10];

void solve()
{
    int i, j;
    if(l==M)
    {
        for(i=0;i<M;i++)
        {
            printf("%d ",stack[i]);
        }
        printf("\n");
        return;
    }
    else
    {
        for(j=1;j<=N;j++)
        {
            stack[l++] = j;
            solve();
            stack[--l] = 0;
        }
    }
}

int main()
{
    scanf("%d %d",&N,&M);
    solve();
    return 0;
}