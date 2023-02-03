# include <stdio.h>
# include <string.h>
int graph[1001][1001], cheak[1001]={0,}, N, answer=0;

void dfs(int node)
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
    int T, num, i, j;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        for(j=0;j<=1000;j++)
            memset(graph[j],0,sizeof(graph[j]));
        answer=0;
        N=0;
        memset(cheak,0,sizeof(cheak));
        scanf("%d",&N);
        for(j=1;j<=N;j++)
        {
            scanf("%d",&num);
            
            graph[j][num]=1;
        }
        
        for(j=1;j<=N;j++)
        {
            if(cheak[j]==0)
            {
                dfs(j);
                answer++;
            }
        }
        printf("%d\n",answer);
    }
    
    return 0;
}