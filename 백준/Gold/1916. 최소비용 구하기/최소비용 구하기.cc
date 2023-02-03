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
vector<vector<pair<int,int>>> v(1002);
int dist[1002];
int visit[1002];
int N, M, start, target;

void init()
{
    for(int i=0;i<1002;i++) {
        dist[i] = INF;
        visit[i] = 0;
    }
}

void dijkstra()
{
    priority_queue<pair<int,int>> pq;
    pq.push({0, start});
    dist[start] = 0;
    visit[start] = 1;

    while(!pq.empty())
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        visit[cur] = 1;
        pq.pop();

        if(dist[cur] < cost) continue;

        for(int i=0;i<v[cur].size();i++)
        {
            int nCost = cost + v[cur][i].first;
            int next = v[cur][i].second;
            if(nCost < dist[next] && visit[next] == 0)
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

    int a, b, d;

    scanf("%d", &N);
    scanf("%d", &M);
    for(int i=0;i<M;i++) {
        scanf("%d %d %d", &a, &b, &d);
        v[a].push_back({d, b});
    }
    scanf("%d %d", &start, &target);

    init();
    dijkstra();

    printf("%d", dist[target]);

    return 0;
}
