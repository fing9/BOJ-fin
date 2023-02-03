#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

#define INF 987654321

using namespace std;

vector<vector<pair<int,int>>> graph(11);
int dist[11], distMax[11];
int n, m, A, B, C;

void dijkstra() {
    priority_queue<pair<int, int>> pq;
    pq.push({0, A});
    distMax[0] = 0;

    while(!pq.empty()) {
        int cur = pq.top().second;
        int cCost = pq.top().first;
        pq.pop();

        for(int i=0;i<graph[cur].size();i++) {
            int next = graph[cur][i].first;
            int nCost = graph[cur][i].second;

            if (cCost + nCost <= C && distMax[next] <= nCost) {
                distMax[next] = max(distMax[cur], nCost);
                pq.push({cCost + nCost, next});
            }
        }
    }
}

void init() {
    for(int i=0;i<11;i++) {
        distMax[i] = -1;
    }
}

int main() {
    init();

    scanf("%d %d %d %d %d", &n, &m, &A, &B, &C);
    for(int i=0;i<m;i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    dijkstra();

    printf("%d", distMax[B]);

    return 0;
}