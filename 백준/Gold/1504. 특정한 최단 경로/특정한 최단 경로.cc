#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#define INF 1987654321

using namespace std;
vector<vector<pair<int,int>>> v(802);
unsigned long long dist[802];

void init()
{
    for(int i=0;i<802;i++)
        dist[i] = INF;
}

void dijkstra(int s)
{
    init();
    priority_queue<pair<unsigned long long,int>> pq;
    pq.push({0,s});
    dist[s] = 0;

    while(!pq.empty())
    {
        unsigned long long cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for(int i=0;i<v[cur].size();i++)
        {
            unsigned long long nCost = cost + v[cur][i].first;
            int next = v[cur][i].second;

            if(nCost < dist[next])
            {
                dist[next] = nCost;
                pq.push({-nCost, next});
            }
        }
    }
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);

    int N, E, a, b, c, v1, v2;
    unsigned long long StoV1, StoV2, V1toV2, V1toN, V2toN, ret = INF;
    scanf("%d %d", &N ,&E);
    for(int i=0;i<E;i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back({c,b});
        v[b].push_back({c,a});
    }
    scanf("%d %d", &v1, &v2);

    dijkstra(1);
    StoV1 = dist[v1];
    StoV2 = dist[v2];

    dijkstra(v1);
    V1toV2 = dist[v2];
    V1toN = dist[N];

    dijkstra(v2);
    V2toN = dist[N];

    ret = min(ret, StoV1 + V1toV2 + V2toN);
    ret = min(ret, StoV2 + V1toV2 + V1toN);

    if(ret>=INF || V1toV2==INF)
        printf("-1");
    else
        printf("%llu", ret);

    return 0;
}
