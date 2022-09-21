#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#define MAX 20002
using namespace std;
int cheak[MAX]={0,}, answer=1;
int V, E;

void dfs(vector<vector<int> >& graph, int node, int color)
{
    cheak[node]=color;
    
    for(int i=0;i<graph[node].size();i++)
    {
        if(cheak[graph[node][i]]==0)
        {
            if(color==1)
                dfs(graph,graph[node][i],2);
            else
                dfs(graph,graph[node][i],1);
        }
        else if(cheak[graph[node][i]]==color)
        {
            answer=0;
            return;
        }
    }
}

int main()
{
    int a, b;
    int K;
    scanf("%d",&K);
    while(K--)
    {
        memset(cheak,0,sizeof(cheak));
        answer=1;
        scanf("%d %d",&V,&E);
        vector<vector<int>> graph(V+1);
        for(int i=0;i<E;i++)
        {
            scanf("%d %d",&a,&b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        for(int i=1;i<=V;i++)
        {
            if(cheak[i]==0 && answer==1)
                dfs(graph,i,1);
            else if(answer==0)
                break;
        }
        
        if(answer==1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    
    return 0;
}