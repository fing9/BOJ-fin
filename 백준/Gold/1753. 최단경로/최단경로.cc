#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#define INF -1987654321
using namespace std;
int dist[20001]={0,};
vector<pair<int,int> > graph[20001];

void dijkstra(int now, int value)
{
    priority_queue<pair<int,int> > pq;
    int v, w;
    
    pq.push(make_pair(value, now));
    
    // 이어진 모든 노드 탐색 & 간선 가중치 갱신
    while(!pq.empty())
    {
        w = pq.top().first;
        v = pq.top().second;
        pq.pop();
        
        for(int i=0;i<graph[v].size();i++)
        {
            int w2 = graph[v][i].first;
            int v2 = graph[v][i].second;
            
			if(w+w2 > dist[v2])
            {
				dist[v2] = w+w2;
				pq.push(make_pair(w+w2,v2));
			}
        }
    }
}

int main()
{
    int V, E, K;
    
    scanf("%d %d", &V, &E);
    scanf("%d", &K);
    
    for(int i=0;i<E;i++)
    {
        int u, a, b;        
        scanf("%d %d %d", &u, &a, &b);
        graph[u].push_back(make_pair(-b, a)); // (가중치, 간선) 순서쌍
    }
    
    for(int i=0;i<=V;i++)
        dist[i] = INF;
    
    dist[K] = 0;
    dijkstra(K, 0);
    
    for(int i=1;i<=V;i++)
    {
        if(dist[i] != INF) printf("%d\n", -dist[i]);
        else printf("INF\n");
    }
    
    return 0;
}