#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

#define INF 987654321

using namespace std;

vector<vector<pair<int, int>>> graph(5001);
int dist[5001];
int V, E, P;
int a, b, c;

void dijkstra(int s) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty()) {
        int cur = pq.top().second;
        int cCost = -pq.top().first;
        pq.pop();

        for(int i=0;i<graph[cur].size();i++) {
            int next = graph[cur][i].first;
            int nCost = graph[cur][i].second;

            if(dist[next] > nCost + cCost) {
                dist[next] = nCost + cCost;
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
    scanf("%d %d %d", &V, &E, &P);

    for(int i=0;i<E;i++) {
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    int ret1, ret2, dest;
    init();
    dijkstra(1);
    ret1 = dist[P];
    dest = dist[V];
    init();
    dijkstra(P);
    ret2 = dist[V];

    if (ret1 + ret2 == dest)
        printf("SAVE HIM");
    else
        printf("GOOD BYE");

    return 0;
}