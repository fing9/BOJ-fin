# include <stdio.h>
int queue[4000001][2], cheak[1000001]={0,};
int head=0, tail=0, ret;
int F, S, G, U, D;

int bfs(int node)
{
    int pop, cnt = 0;
    queue[tail][0]=node;
    queue[tail++][1]=1;
    cheak[node]=1;
    
    while(head<tail)
    {
        pop=queue[head][0];
        cnt=queue[head++][1];
        
        if(pop==G)
            return cnt;
        if(pop-D>0) {
            if(cheak[pop-D]==0)
            {
                queue[tail][0]=pop-D;
                queue[tail++][1]=cnt+1;
                cheak[pop-D]=1;
            }
        }
        if(pop+U<F+1) {
            if(cheak[pop+U]==0)
            {
                queue[tail][0]=pop+U;
                queue[tail++][1]=cnt+1;
                cheak[pop+U]=1;
            }
        }
    }
    
    return 1;
}


int main()
{
    int i;
    scanf("%d %d %d %d %d",&F,&S,&G,&U,&D);
    
    if(G==S)
    {
        printf("0");
        return 0;
    }
    else if(G<S && D==0)
    {
        printf("use the stairs");
        return 0;
    }
    else if(G>S && U==0)
    {
        printf("use the stairs");
        return 0;
    }
    
    ret = bfs(S)-1;
    
    if(cheak[G] == 0)
        printf("use the stairs");
    else
        printf("%d", ret);
    
    return 0;
}