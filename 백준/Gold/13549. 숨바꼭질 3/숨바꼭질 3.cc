#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <cmath>

#define INF 987654321

using namespace std;
vector<vector<pair<int,int>>> graph(100001);
int dist[100001];

void init()
{
    for(int i=0;i<100001;i++) {
        dist[i] = INF;
        if(i != 0)
            graph[i].push_back({0,i-1});
        if(i != 100000)
            graph[i].push_back({1,i+1});
        if(i*2 <= 100000 && i != 0)
            graph[i].push_back({2,i*2});
    }
}

void dijkstra(int N)
{
    priority_queue<pair<int,int>> pq;
    pq.push({0,N});
    dist[N] = 0;

    while(!pq.empty())
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(dist[cur] < cost) continue;

        for(int i=0;i<graph[cur].size();i++)
        {
            int nCost;
            int step = graph[cur][i].first;
            int next = graph[cur][i].second;
            if(step == 2) nCost = cost;
            else nCost = cost + 1;

            if(nCost < dist[next])
            {
                dist[next] = nCost;
                pq.push({-nCost,next});
            }
        }
    }
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    init();

    int N, K;
    scanf("%d %d", &N, &K);

    dijkstra(N);

    printf("%d", dist[K]);

    return 0;
}