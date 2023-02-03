#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
#define INF 1987654321

using namespace std;

vector<vector<pair<int, int>>> graph(1001);
vector<int> ans;
int dist[1001];
int route[1001], len;

void dijkstra(int s, int d) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while(!pq.empty()) {
        int cur = pq.top().second;
        int cCost = -pq.top().first;
        pq.pop();

        if(cCost > dist[cur]) {
            continue;
        }

        for(int i=0;i<graph[cur].size();i++) {
            int next = graph[cur][i].first;
            int nCost = cCost + graph[cur][i].second;

            if(dist[next] > nCost) {
                route[next] = cur;
                dist[next] = nCost;
                pq.push({-nCost, next});
            }
        }
    }

    printf("%d\n", dist[d]);
    while(d != 0) {
        ans.push_back(d);
        d = route[d];
    }
    len = ans.size();

    printf("%d\n", len);
    for(int i=len-1;i>=0;i--) {
        printf("%d ", ans[i]);
    }
}

void init() {
    for(int i=0;i<1001;i++) {
        dist[i] = INF;
        route[i] = 0;
    }
}

int main() {
    int n, m, a, b, c;
    int s, d;
    int ans = INF;
    scanf("%d\n%d", &n, &m);
    for(int i=0;i<m;i++) {
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back({b, c});
    }
    scanf("%d %d", &s, &d);

    init();
    dijkstra(s, d);

    return 0;
}