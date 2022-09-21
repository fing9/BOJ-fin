# include <stdio.h>
# include <stdlib.h>
# include <string.h>
int map[10][10], cheak[10][10], cpymap[10][10];
int queue[100000][2], head=0, tail=0;
int N, M, max=0;

void bfs(int x, int y)
{
    int popx, popy;
    queue[tail][0]=x;
    queue[tail++][1]=y;
    cpymap[x][y]=2;
    cheak[x][y]=1;
    
    while(head<tail)
    {
        popx=queue[head][0];
        popy=queue[head++][1];
        
        if(cpymap[popx+1][popy]==0 && cheak[popx+1][popy]==0)
        {
            queue[tail][0]=popx+1;
            queue[tail++][1]=popy;
            cpymap[popx+1][popy]=2;
            cheak[popx+1][popy]=1;
        }
        if(cpymap[popx][popy+1]==0 && cheak[popx][popy+1]==0)
        {
            queue[tail][0]=popx;
            queue[tail++][1]=popy+1;
            cpymap[popx][popy+1]=2;
            cheak[popx][popy+1]=1;
        }
        if(cpymap[popx-1][popy]==0 && cheak[popx-1][popy]==0)
        {
            queue[tail][0]=popx-1;
            queue[tail++][1]=popy;
            cpymap[popx-1][popy]=2;
            cheak[popx-1][popy]=1;
        }
        if(cpymap[popx][popy-1]==0 && cheak[popx][popy-1]==0)
        {
            queue[tail][0]=popx;
            queue[tail++][1]=popy-1;
            cpymap[popx][popy-1]=2;
            cheak[popx][popy-1]=1;
        }
    }
}

void mapcopy()
{
    int i, j;
    
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
            cpymap[i][j]=map[i][j];
    }
}

void wall(int cnt)
{
    int i, j, count=0;
    
    if(cnt==3)
    {
        head=0;
        tail=0;
        mapcopy();
        for(i=0;i<10;i++)
            memset(cheak[i],0,sizeof(cheak[i]));
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=M;j++)
            {
                if(cpymap[i][j]==2 && cheak[i][j]==0)
                    bfs(i,j);
            }
        }
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=M;j++)
            {
                if(cpymap[i][j]==0)
                    count++;
            }
        }
        if(count>max)
            max=count;
        return 0;
    }
    
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=M;j++)
        {
            if(map[i][j]==0)
            {
                map[i][j]=1;
                wall(cnt+1);
                map[i][j]=0;
            }
        }
    }
}

int main()
{
    int i, j;
    scanf("%d %d",&N,&M);
    
    for(i=0;i<10;i++) // reset
    {
        for(j=0;j<10;j++)
        {
            map[i][j]=1;
            cpymap[i][j]=1;
        }
    }
    for(i=0;i<10;i++)
        memset(cheak[i],0,sizeof(cheak[i]));
    
    for(i=1;i<=N;i++) // input
    {
        for(j=1;j<=M;j++)
            scanf("%d",&map[i][j]);
    }
    
    wall(0);
    printf("%d",max);
    return 0;
}