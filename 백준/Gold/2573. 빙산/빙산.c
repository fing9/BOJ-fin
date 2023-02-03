# include <stdio.h>
# include <string.h>
int N, M;
int map[302][302], cheak[302][302], melt[302][302], spa=0, year=1;
int queue[100000][2], head=0, tail=0;

void dfs(int x, int y)
{
    int i, j;
    cheak[x][y]=2;
    
    if(map[x+1][y]>0 && cheak[x+1][y]==1)
        dfs(x+1,y);
    if(map[x][y+1]>0 && cheak[x][y+1]==1)
        dfs(x,y+1);
    if(map[x-1][y]>0 && cheak[x-1][y]==1)
        dfs(x-1,y);
    if(map[x][y-1]>0 && cheak[x][y-1]==1)
        dfs(x,y-1);
}

void bfs(int x, int y)
{
    int popx, popy;
    queue[tail][0]=x;
    queue[tail++][1]=y;
    cheak[x][y]=1;
    
    while(head<tail)
    {
        popx=queue[head][0];
        popy=queue[head++][1];
        
        if(map[popx+1][popy]>0 && cheak[popx+1][popy]==0)
        {
            queue[tail][0]=popx+1;
            queue[tail++][1]=popy;
            cheak[popx+1][popy]=1;
        }
        else if(map[popx+1][popy]<=0)
            melt[popx][popy]+=1;
        if(map[popx][popy+1]>0 && cheak[popx][popy+1]==0)
        {
            queue[tail][0]=popx;
            queue[tail++][1]=popy+1;
            cheak[popx][popy+1]=1;
        }
        else if(map[popx][popy+1]<=0)
            melt[popx][popy]+=1;
        if(map[popx-1][popy]>0 && cheak[popx-1][popy]==0)
        {
            queue[tail][0]=popx-1;
            queue[tail++][1]=popy;
            cheak[popx-1][popy]=1;
        }
        else if(map[popx-1][popy]<=0)
            melt[popx][popy]+=1;
        if(map[popx][popy-1]>0 && cheak[popx][popy-1]==0)
        {
            queue[tail][0]=popx;
            queue[tail++][1]=popy-1;
            cheak[popx][popy-1]=1;
        }
        else if(map[popx][popy-1]<=0)
            melt[popx][popy]+=1;
    }
}

int main()
{
    int i, j, l;
    for(l=0;l<302;l++) // reset
    {
        memset(map[l],0,sizeof(map[l]));
        memset(cheak[l],0,sizeof(cheak[l]));
        memset(melt[l],0,sizeof(melt[l]));
    }
    scanf("%d %d",&N,&M);
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=M;j++)
        {
            scanf("%d",&map[i][j]);
        }
    }
    
    while(1)
    {
        spa=0;
        head=0;
        tail=0;
        for(l=0;l<302;l++) // reset
        {
            memset(cheak[l],0,sizeof(cheak[l]));
            memset(melt[l],0,sizeof(melt[l]));
        }
        
        for(i=1;i<=N;i++) // 빙하 조사
        {
            for(j=1;j<=M;j++)
            {
                if(map[i][j]>0 && cheak[i][j]==0)
                {
                    bfs(i,j);
               }
            }
        }
        
        for(i=1;i<=N;i++) // 녹이기
        {
            for(j=1;j<=M;j++)
            {
                map[i][j]-=melt[i][j];
            }
        }
        
        for(i=1;i<=N;i++) // 섬갯수 조사
        {
            for(j=1;j<=M;j++)
            {
                if(map[i][j]>0 && cheak[i][j]==1)
                {
                    dfs(i,j);
                    spa+=1;
                }
            }
        }
        if(spa>=2)
        {
            printf("%d",year);
            return 0;
        }
        else if(spa==0)
        {
            printf("0");
            return 0;
        }
        year+=1;
    }
    return 0;
}