# include <stdio.h>
# include <string.h>
int map[102][102], cheak[102][102], height=0, lands=0, max_lands=0;

void dfs(int x, int y, int h)
{
    cheak[x][y]=1;
    
    if(map[x+1][y]>h && cheak[x+1][y]==0)
        dfs(x+1,y,h);
    if(map[x][y+1]>h && cheak[x][y+1]==0)
        dfs(x,y+1,h);
    if(map[x-1][y]>h && cheak[x-1][y]==0)
        dfs(x-1,y,h);
    if(map[x][y-1]>h && cheak[x][y-1]==0)
        dfs(x,y-1,h);
}

int main()
{
    int N, i, j, k, l;
    scanf("%d",&N);
    
    for(i=0;i<102;i++)
    {
        for(j=0;j<102;j++)
        {
            memset(map[i],0,sizeof(map[i]));
            memset(cheak[i],0,sizeof(cheak[i]));
        }
    }
    
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
        {
            scanf("%d",&map[i][j]);
            if(map[i][j]>height)
                height=map[i][j];
        }
    }
    
    for(l=0;l<height;l++)
    {
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=N;j++)
            {
                if(map[i][j]>l && cheak[i][j]==0)
                {
                    dfs(i,j,l);
                    lands++;
                }
            }
        }
        if(lands>max_lands)
            max_lands = lands;
        lands=0;
        for(k=0;k<102;k++)
            memset(cheak[k],0,sizeof(cheak[k]));
    }
    
    printf("%d",max_lands);
    
    return 0;
}