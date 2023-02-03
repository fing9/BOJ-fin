# include <stdio.h>
# include <string.h>
int map[52][52], cheak[52][52], answer=0;

void dfs(int x, int y)
{
    cheak[x][y]=1;
    if(map[x+1][y]==1 && cheak[x+1][y]==0)
        dfs(x+1,y);
    if(map[x][y+1]==1 && cheak[x][y+1]==0)
        dfs(x,y+1);
    if(map[x-1][y]==1 && cheak[x-1][y]==0)
        dfs(x-1,y);
    if(map[x][y-1]==1 && cheak[x][y-1]==0)
        dfs(x,y-1);
}

int main()
{
    int T, M, N, K;
    int a, b;
    int i, j;
    scanf("%d",&T);
    while(T--)
    {
        for(i=0;i<52;i++)
        {
            memset(map[i],0,sizeof(map[i]));
            memset(cheak[i],0,sizeof(cheak[i]));
        }
        answer=0;
        scanf("%d %d %d",&M,&N,&K);
        for(i=0;i<K;i++)
        {
            scanf("%d %d",&a,&b);
            a++;
            b++;
            map[a][b]=1;
        }
        
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=M;j++)
            {
                if(map[j][i]==1 && cheak[j][i]==0)
                {
                    dfs(j,i);
                    answer++;
                }
            }
        }
        
        printf("%d\n",answer);
    }
    return 0;
}