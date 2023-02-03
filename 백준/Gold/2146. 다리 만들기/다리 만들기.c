# include <stdio.h>
# include <string.h>
int map[103][103], cheak[103][103], now, t=2;
int queue[1000003][3], head=1, tail=1;
int answer=10000000;
int N;

int min(int a, int b)
{
    if(a<=b)
        return a;
    else
        return b;
}

void dfs(int x, int y)
{
    cheak[x][y]=1;
    map[x][y]=t;
    
    if(x+1>0 && y>0 && x+1<=N && y<=N && map[x+1][y]!=0 && cheak[x+1][y]==0)
        dfs(x+1,y);
    if(x>0 && y+1>0 && x<=N && y+1<=N && map[x][y+1]!=0 && cheak[x][y+1]==0)
        dfs(x,y+1);
    if(x-1>0 && y>0 && x-1<=N && y<=N && map[x-1][y]!=0 && cheak[x-1][y]==0)
        dfs(x-1,y);
    if(x>0 && y-1>0 && x<=N && y-1<=N && map[x][y-1]!=0 && cheak[x][y-1]==0)
        dfs(x,y-1);
}

void bfs(int x, int y, int d)
{
    int pop_x, pop_y, pop_d;
    queue[tail][0]=x;
    queue[tail][1]=y;
    queue[tail++][2]=d;
    cheak[x][y]=d;
    
    while(head<tail)
    {
        pop_x=queue[head][0];
        pop_y=queue[head][1];
        pop_d=queue[head++][2];
        
        if(pop_x+1>0 && pop_y>0 && pop_x+1<=N && pop_y<=N && map[pop_x+1][pop_y]==0 && cheak[pop_x+1][pop_y]==0)
        {
            queue[tail][0]=pop_x+1;
            queue[tail][1]=pop_y;
            queue[tail++][2]=pop_d+1;
            cheak[pop_x+1][pop_y]=pop_d+1;
        }
        else if(pop_x+1>0 && pop_y>0 && pop_x+1<=N && pop_y<=N && map[pop_x+1][pop_y]!=0 && map[pop_x+1][pop_y]!=now && cheak[pop_x+1][pop_y]==0)
            answer=min(answer,pop_d);
        
        if(pop_x>0 && pop_y+1>0 && pop_x<=N && pop_y+1<=N && map[pop_x][pop_y+1]==0 && cheak[pop_x][pop_y+1]==0)
        {
            queue[tail][0]=pop_x;
            queue[tail][1]=pop_y+1;
            queue[tail++][2]=pop_d+1;
            cheak[pop_x][pop_y+1]=pop_d+1;
        }
        else if(pop_x>0 && pop_y+1>0 && pop_x<=N && pop_y+1<=N && map[pop_x][pop_y+1]!=0 && map[pop_x][pop_y+1]!=now && cheak[pop_x][pop_y+1]==0)
            answer=min(answer,pop_d);
        
        if(pop_x-1>0 && pop_y>0 && pop_x-1<=N && pop_y<=N && map[pop_x-1][pop_y]==0 && cheak[pop_x-1][pop_y]==0)
        {
            queue[tail][0]=pop_x-1;
            queue[tail][1]=pop_y;
            queue[tail++][2]=pop_d+1;
            cheak[pop_x-1][pop_y]=pop_d+1;
        }
        else if(pop_x-1>0 && pop_y>0 && pop_x-1<=N && pop_y<=N && map[pop_x-1][pop_y]!=0 && map[pop_x-1][pop_y]!=now && cheak[pop_x-1][pop_y]==0)
            answer=min(answer,pop_d);
        
        if(pop_x>0 && pop_y-1>0 && pop_x<=N && pop_y-1<=N && map[pop_x][pop_y-1]==0 && cheak[pop_x][pop_y-1]==0)
        {
            queue[tail][0]=pop_x;
            queue[tail][1]=pop_y-1;
            queue[tail++][2]=pop_d+1;
            cheak[pop_x][pop_y-1]=pop_d+1;
        }
        else if(pop_x>0 && pop_y-1>0 && pop_x<=N && pop_y-1<=N && map[pop_x][pop_y-1]!=0 && map[pop_x][pop_y-1]!=now && cheak[pop_x][pop_y-1]==0)
            answer=min(answer,pop_d);
    }
}

int main()
{
    int i, j, k;
    for(i=0;i<103;i++) // reset
    {
        memset(map[i],-1,sizeof(map[i]));
        memset(cheak[i],0,sizeof(cheak[i]));
    }
    for(i=0;i<1000003;i++)
        memset(queue[i],0,sizeof(queue[i]));
    
    scanf("%d",&N); // input
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
            scanf("%d",&map[i][j]);
    }
    
    for(i=1;i<=N;i++) // 각 대륙 번호로 나누기 [dfs]
    {
        for(j=1;j<=N;j++)
        {
            if(map[i][j]!=0 && cheak[i][j]==0)
            {
                dfs(i,j);
                t++;
            }
        }
    }
    
    for(i=0;i<103;i++) // reset_cheak
        memset(cheak[i],0,sizeof(cheak[i]));
    
    for(i=1;i<=N;i++) // 가장 짧은 다리놓기 [bfs]
    {
        for(j=1;j<=N;j++)
        {
            if(map[i][j]!=0 && map[i][j]!=-1 && cheak[i][j]==0)
            {
                now=map[i][j];
                bfs(i,j,0);
            }
            for(k=0;k<103;k++) // reset
                memset(cheak[k],0,sizeof(cheak[k]));
            head=0;
            tail=0;
        }
    }
    
    printf("%d",answer);
    
    return 0;
}