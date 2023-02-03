#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int graph[102][102], cheak[102];
int N;

void dfs(int vertex)
{
    for(int i=0;i<N;i++)
    {
        if(graph[vertex][i]==1 && cheak[i]==0)
        {
            cheak[i]=1;
            dfs(i);
        }
    }
}

int main()
{
    scanf("%d",&N);
    
    for(int i=0;i<102;i++) // reset
    {
        for(int j=0;j<102;j++)
            graph[i][j]=0;
        cheak[i]=0;
    }
    
    for(int i=0;i<N;i++) // input
    {
        for(int j=0;j<N;j++)
            scanf("%d",&graph[i][j]);
    }
    
    for(int i=0;i<N;i++) // solve
    {
        for(int j=0;j<102;j++)
            cheak[j]=0;
        dfs(i);
        for(int j=0;j<N;j++)
        {
            if(cheak[j]==1)
                graph[i][j]=1;
        }
    }
    
    for(int i=0;i<N;i++) // output
    {
        for(int j=0;j<N;j++)
        {
            printf("%d",graph[i][j]);
            if(j!=N-1)
                printf(" ");
        }
        if(i!=N-1)
            printf("\n");
    }
    
    return 0;
}