# include <stdio.h>
# include <string.h>
char map[52][52], trans[52][52], answer=0;
int cheak[52][52], queue[2502][4], head=0, tail=0;

int max(int a, int b)
{
    if(a>=b)
        return a;
    else
        return b;
}

void bfs(int x, int y, int l)
{
    int pop_x, pop_y, pop_l;
    queue[tail][0]=x;
    queue[tail][1]=y;
    queue[tail++][2]=l;
    cheak[x][y]=l;
    answer=max(answer,l);
    
    while(head<tail)
    {
        pop_x=queue[head][0];
        pop_y=queue[head][1];
        pop_l=queue[head++][2];
        
        if(map[pop_x+1][pop_y]=='L' && cheak[pop_x+1][pop_y]==0)
        {
            queue[tail][0]=pop_x+1;
            queue[tail][1]=pop_y;
            queue[tail++][2]=pop_l+1;
            cheak[pop_x+1][pop_y]=pop_l+1;
            answer=max(answer,pop_l+1);
        }
        if(map[pop_x][pop_y+1]=='L' && cheak[pop_x][pop_y+1]==0)
        {
            queue[tail][0]=pop_x;
            queue[tail][1]=pop_y+1;
            queue[tail++][2]=pop_l+1;
            cheak[pop_x][pop_y+1]=pop_l+1;
            answer=max(answer,pop_l+1);
        }
        if(map[pop_x-1][pop_y]=='L' && cheak[pop_x-1][pop_y]==0)
        {
            queue[tail][0]=pop_x-1;
            queue[tail][1]=pop_y;
            queue[tail++][2]=pop_l+1;
            cheak[pop_x-1][pop_y]=pop_l+1;
            answer=max(answer,pop_l+1);
        }
        if(map[pop_x][pop_y-1]=='L' && cheak[pop_x][pop_y-1]==0)
        {
            queue[tail][0]=pop_x;
            queue[tail][1]=pop_y-1;
            queue[tail++][2]=pop_l+1;
            cheak[pop_x][pop_y-1]=pop_l+1;
            answer=max(answer,pop_l+1);
        }
    }
}

main()
{
    int L, W;
    int i, j, o, p, u;
    scanf("%d %d",&L,&W);
    
    for(i=0;i<52;i++) //reset
    {
        memset(map[i],NULL,sizeof(map[i]));
        memset(trans[i],NULL,sizeof(trans[i]));
        memset(cheak[i],0,sizeof(cheak[i]));
    }
    for(i=0;i<2502;i++)
        memset(queue[i],0,sizeof(queue[i]));
    head=0;
    tail=0;
    
    for(i=1;i<=L;i++) //input
        scanf("%s",&trans[i]);
    for(i=1;i<=L;i++)
    {
        for(j=1;j<=W;j++)
            map[i][j]=trans[i][j-1];
    }
    
    for(i=1;i<=L;i++)
    {
        for(j=1;j<=W;j++)
        {
            if(map[i][j]=='L' && cheak[i][j]==0)
            {
                bfs(i,j,1);
                for(p=0;p<52;p++) //reset
                    memset(cheak[p],0,sizeof(cheak[p]));
                for(u=0;u<2502;u++)
                    memset(queue[u],0,sizeof(queue[u]));
                head=0;
                tail=0;
            }
        }
    }

    printf("%d",answer-1);
    
    return 0;
}