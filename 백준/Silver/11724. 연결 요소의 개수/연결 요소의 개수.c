# include <stdio.h>
int graph[1001][1001], cheak[1001]={0,}, answer=0;
int N, M;
 
int dfs(int node)
{
    int i;
    cheak[node]=1;
 
    for(i=1;i<=N;i++)
    {
        if(graph[node][i]==1 && cheak[i]==0)
            dfs(i);
    }
}
 
int main()
{
    int i;
    int u, v;
    scanf("%d %d",&N,&M);
    for(i=0;i<M;i++)
    {
        scanf("%d %d",&u,&v);
 
        graph[u][v]=1;
        graph[v][u]=1;
    }
 
    for(i=1;i<=N;i++)
    {
        if(cheak[i]==0)
        {
            dfs(i);
            answer++;
        }
    }
 
    printf("%d",answer);
 
    return 0;
}