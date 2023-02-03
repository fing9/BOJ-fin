# include <stdio.h>
# include <string.h>
int map[102][102], cheak[102][102];
int queue[10003][3], head=0; tail=0;
char trans[102][102];

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
        
        if(map[pop_x+1][pop_y]==1 && cheak[pop_x+1][pop_y]==0)
        {
            queue[tail][0]=pop_x+1;
            queue[tail][1]=pop_y;
            queue[tail++][2]=pop_d+1;
            cheak[pop_x+1][pop_y]=pop_d+1;
        }
        if(map[pop_x][pop_y+1]==1 && cheak[pop_x][pop_y+1]==0)
        {
            queue[tail][0]=pop_x;
            queue[tail][1]=pop_y+1;
            queue[tail++][2]=pop_d+1;
            cheak[pop_x][pop_y+1]=pop_d+1;
        }
        if(map[pop_x-1][pop_y]==1 && cheak[pop_x-1][pop_y]==0)
        {
            queue[tail][0]=pop_x-1;
            queue[tail][1]=pop_y;
            queue[tail++][2]=pop_d+1;
            cheak[pop_x-1][pop_y]=pop_d+1;
        }
        if(map[pop_x][pop_y-1]==1 && cheak[pop_x][pop_y-1]==0)
        {
            queue[tail][0]=pop_x;
            queue[tail][1]=pop_y-1;
            queue[tail++][2]=pop_d+1;
            cheak[pop_x][pop_y-1]=pop_d+1;
        }
    }
}

int main()
{
    int N, M;
    int i, j;
    scanf("%d %d",&N,&M);
    
    for(i=0;i<102;i++) //reset
    {
        memset(map[i],0,sizeof(map[i]));
        memset(cheak[i],0,sizeof(cheak[i]));
        memset(trans[i],NULL,sizeof(trans[i]));
    }
    for(i=0;i<10003;i++)
        memset(queue[i],NULL,sizeof(queue[i]));
    
    
    for(i=1;i<=N;i++)
        scanf("%s",&trans[i]);
    
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=M;j++)
            map[i][j]=trans[i][j-1]-48;
    }
    
    bfs(1,1,1);
    
    printf("%d",cheak[N][M]);
    
    return 0;
}