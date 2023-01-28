#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

#define INF 987654321

using namespace std;

vector<vector<pair<int,int>>> graph(5001);
int dist[5001];
int n, m;
int s, t;

void dijkstra() {
    priority_queue<pair<int, int>> pq;
    pq.push({0, s});

    while(!pq.empty()) {
        int cur = pq.top().second;
        int cCost = -pq.top().first;
        pq.pop();

        for(int i=0;i<graph[cur].size();i++) {
            int next = graph[cur][i].first;
            int nCost = graph[cur][i].second;

            if (dist[next] > cCost + nCost) {
                dist[next] = cCost + nCost;
                pq.push({-dist[next], next});
            }
        }
    }
}

void init() {
    for(int i=0;i<5001;i++) {
        dist[i] = INF;
    }
}

int main() {
    init();

    scanf("%d %d", &n, &m);
    for(int i=0;i<m;i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    scanf("%d %d", &s, &t);

    dijkstra();

    printf("%d", dist[t]);

    return 0;
}