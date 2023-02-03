# include <stdio.h>
# include <string.h>
int map[102][102], cheak[102]={0,}, answer=0;

void dfs(int node)
{
    int i;
    cheak[node]=1;
    answer++;
    
    for(i=1;i<=100;i++)
    {
        if(map[node][i]==1 && cheak[i]==0)
            dfs(i);
    }
}

int main()
{
    int N, M;
    int a, b, i, j;
    
    for(i=0;i<103;i++)
        memset(map[i],0,sizeof(map[i]));
    
    scanf("%d",&N);
    scanf("%d",&M);
    
    for(i=1;i<=M;i++)
    {
        scanf("%d %d",&a,&b);
        map[a][b]=1;
        map[b][a]=1;
    }
    
    dfs(1);
    
    printf("%d",answer-1);
    
    return 0;
}