# include <stdio.h>
int N, M, l=0;
int stack[10];

void solve(int to_num)
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
        for(j=to_num;j<=N;j++)
        {
            stack[l++] = j;
            solve(j+1);
            stack[--l] = 0;
        }
    }
}

int main()
{
    scanf("%d %d",&N,&M);
    solve(1);
    return 0;
}