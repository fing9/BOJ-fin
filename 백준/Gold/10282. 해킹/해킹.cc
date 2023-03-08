#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

#define INF 987654321

using namespace std;

vector<vector<pair<int, int>>> graph(10001);
int dist[10001];
int n, d, c;
int ans_cnt, ans_time;

void    init() {
    for (int i=0;i<10001;i++) {
        graph[i].clear();
        dist[i] = INF;
    }
    ans_time = 0;
    ans_cnt = 0;
}

void    dijkstra(int s) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty()) {
        int cur = pq.top().second;
        int cCost = -pq.top().first;
        pq.pop();

        for (int i=0;i<graph[cur].size();i++) {
            int next = graph[cur][i].first;
            int nCost = graph[cur][i].second;

            if (dist[next] > nCost + cCost) {
                dist[next] = nCost + cCost;
                pq.push({-(nCost + cCost), next});
            }
        }
    }
}

void    getAnswer() {
    for (int i=1;i<=n;i++) {
        if (dist[i] != INF) {
            ans_cnt++;
            if (ans_time < dist[i])
                ans_time = dist[i];
        }
    }
}

int main() {
    int t;

    scanf("%d", &t);
    while (t--) {
        init();
        scanf("%d %d %d", &n, &d, &c);
        for (int i=0;i<d;i++) {
            int a, b, s;
            scanf("%d %d %d", &a, &b, &s);
            graph[b].push_back({a, s});
        }
        dijkstra(c);
        getAnswer();
        printf("%d %d\n", ans_cnt, ans_time);
    }
}