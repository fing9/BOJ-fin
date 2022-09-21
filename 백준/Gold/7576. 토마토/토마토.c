# include <stdio.h>
# include <string.h>
int box[1001][1001], cheak[1001][1001], is_in=0;
int queue[1000001][3], head=0, tail=0;
int max=0;


void bfs(int x, int y, int day)
{
    int pop_x, pop_y, pop_day;
    
    while(head<tail)
    {
        pop_x=queue[head][0];
        pop_y=queue[head][1];
        pop_day=queue[head++][2];
        
        if(box[pop_x+1][pop_y]==0 && cheak[pop_x+1][pop_y]==0)
        {
            queue[tail][0]=pop_x+1;
            queue[tail][1]=pop_y;
            queue[tail++][2]=pop_day+1;
            cheak[pop_x+1][pop_y]=pop_day+1;
        }
        if(box[pop_x][pop_y+1]==0 && cheak[pop_x][pop_y+1]==0)
        {
            queue[tail][0]=pop_x;
            queue[tail][1]=pop_y+1;
            queue[tail++][2]=pop_day+1;
            cheak[pop_x][pop_y+1]=pop_day+1;
        }
        if(box[pop_x-1][pop_y]==0 && cheak[pop_x-1][pop_y]==0)
        {
            queue[tail][0]=pop_x-1;
            queue[tail][1]=pop_y;
            queue[tail++][2]=pop_day+1;
            cheak[pop_x-1][pop_y]=pop_day+1;
        }
        if(box[pop_x][pop_y-1]==0 && cheak[pop_x][pop_y-1]==0)
        {
            queue[tail][0]=pop_x;
            queue[tail][1]=pop_y-1;
            queue[tail++][2]=pop_day+1;
            cheak[pop_x][pop_y-1]=pop_day+1;
        }
    }
}

int main()
{
    int i, j;
    int M, N;
    scanf("%d %d",&M,&N);
    
    for(i=0;i<1000001;i++)
        memset(queue[i],0,sizeof(queue[i]));
    for(i=0;i<1001;i++)
    {
        memset(box[i],-1,sizeof(box[i]));
        memset(cheak[i],0,sizeof(cheak[i]));
    }
    
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=M;j++)
        {
            scanf("%d",&box[i][j]);
            if(box[i][j]==1)
            {
                is_in++;
                queue[tail][0]=i;
                queue[tail][1]=j;
                queue[tail++][2]=1;
                cheak[i][j]=1;
            }
            if(box[i][j]==-1)
                cheak[i][j]=-1;
        }
    }
    
    if(is_in==(N*M))
    {
        printf("0");
        return 0;
    }
    
    bfs(i,j,1);
    
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=M;j++)
        {
            if(cheak[i][j]-1>max && cheak[i][j]!=-1 && cheak[i][j]!=0)
                max=cheak[i][j]-1;
        }
    }
    
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=M;j++)
        {
            if(cheak[i][j]==0)
            {
                printf("-1");
                return 0;
            }
        }
    }
    
    printf("%d",max);
    return 0;
}