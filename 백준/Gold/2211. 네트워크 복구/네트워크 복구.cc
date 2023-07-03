#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <bitset>

#define INF 1147483647
#define LLINF 223372036854775807

using namespace std;

int N, M;
int dist[1001];
int visited[1001];
vector<vector<pair<int, int>>> graph(1001);
vector<pair<int, int>> retV;

void init() {
    for (int i=0;i<1001;i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
}

void dijkstra(int s) {
    priority_queue<pair<int, int>> pq;
    pq.push({s, 0});
    dist[s] = 0;

    while (!pq.empty()) {
        int cur = pq.top().first;
        int cost = -pq.top().second;
        pq.pop();

        for (int i=0;i<graph[cur].size();i++) {
            int next = graph[cur][i].first;
            int nCost = graph[cur][i].second + cost;

            if (dist[next] > nCost) {
                dist[next] = nCost;
                pq.push({next, -nCost});
            }
        }
    }
}

int bfs(int s) {
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push({s, 0});
    visited[s] = 1;

    while (!q.empty()) {
        int cur = q.front().first;
        int cost = q.front().second;
        q.pop();

        for (int i=0;i<graph[cur].size();i++) {
            int next = graph[cur][i].first;
            int nCost = graph[cur][i].second + cost;

            if (dist[next] == nCost && visited[next] == 0) {
                retV.push_back({cur, next});
                q.push({next, nCost});
                visited[next] = 1;
                cnt++;
            }
        }
    }

    return (cnt);
}

int main() {
    init();

    scanf("%d %d", &N, &M);
    for (int i=0;i<M;i++) {
        int a, b, c;

        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    dijkstra(1);
    printf("%d\n", bfs(1));
    for (int i=0;i<retV.size();i++) {
        printf("%d %d\n", retV[i].first, retV[i].second);
    }

    return 0;
}