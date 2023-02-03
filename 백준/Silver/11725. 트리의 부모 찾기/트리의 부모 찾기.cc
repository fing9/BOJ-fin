#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#define INF 987654321
using namespace std;
vector<vector<int>> tree(100001,vector<int>(0,0));
int tree_parent[100001]={0,};

void solve(int node)
{
    for(int i=0;i<tree[node].size();i++)
    {
        if(tree_parent[tree[node][i]]==0)
        {
            tree_parent[tree[node][i]]=node;
            solve(tree[node][i]);
        }
    }
    return;
}

int main()
{
    int N, node_a, node_b;
    scanf("%d",&N);

    for(int i=0;i<N;i++)
    {
        scanf("%d %d",&node_a,&node_b);
        tree[node_a].push_back(node_b);
        tree[node_b].push_back(node_a);
    }
    solve(1);
    for(int i=2;i<=N;i++)
    {
        printf("%d\n",tree_parent[i]);
    }

    return 0;
}