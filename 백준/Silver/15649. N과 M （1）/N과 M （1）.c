# include <stdio.h>
int used[9];
int l=0;

void solve(int N, int k, int depth)
{
    int i, j, cheak=0;
    
    if(k==depth)
    {
        for(i=0;i<l;i++)
            printf("%d ",used[i]);
        printf("\n");
        return;
    }
    else
    {
        for(i=1;i<=N;i++)
        {
            cheak=0;
            if(l==0)
            {
                used[l++] = i;
                solve(N,k,depth+1);
                used[--l] = 0;
            }
            else
            {
                for(j=0;j<l;j++)
                {
                    if(used[j]==i)
                        cheak = 1;
                }
                if(cheak==0)
                {
                    used[l++] = i;
                    solve(N,k,depth+1);
                    used[--l] = 0;
                }
            }
        }
    }
}

int main()
{
    int N, M;
    scanf("%d %d",&N,&M);
    solve(N,M,0);
    return 0;
}