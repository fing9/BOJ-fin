# include <stdio.h>
# include <string.h>
int cheak[1002]={0,}, graph[1001][1001];
int N, M, V;
int queue[1002]={0,}, head=1, tail=1;

void dfs(int now_node)
{
    int next, i;
    printf("%d ",now_node);
    cheak[now_node]=1;
    
    for(i=1;i<=N;i++)
    {
        if(graph[now_node][i]!=0)
        {
            next=i;
        
            if(cheak[next]!=1)
            {
                dfs(next);
            }
        }
    }
}

void bfs(int node)
{
    int pop, i;
    printf("%d ",node);
    queue[tail++]=node;
    cheak[node]=1;
    
    while(head<tail)
    {
        pop=queue[head++];
        
        for(i=1;i<=N;i++)
        {
            if(graph[pop][i]==1 && cheak[i]==0)
            {
                printf("%d ",i);
                queue[tail++]=i;
                cheak[i]=1;
            }
        }
    }
}

int main()
{
    int i, a, b;
    
    scanf("%d %d %d",&N,&M,&V);
    
    for(i=1;i<=N;i++)
    {
        memset(graph[i],0,sizeof(graph[i]));
    }
    
    for(i=1;i<=M;i++)
    {
        scanf("%d %d",&a,&b);
        
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    
    dfs(V);
    printf("\n");
    memset(cheak,0,sizeof(cheak));
    bfs(V);
    
    return 0;
}