#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <utility>
#include <bitset>

#define FAST ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define INT_MAX 2147483647
#define LL_MAX 9223372036854775807
#define MAX 987654321
#define MIN -987654321
#define ll long long
#define GRAPH vector<vector<pair<int, int>>>

using namespace std;

GRAPH graph(100001);
int C, P, PB, PA1, PA2;
int dist[3][100001];

void init() {
    for (int i=0;i<100001;i++) {
        dist[0][i] = INT_MAX;
        dist[1][i] = INT_MAX;
        dist[2][i] = INT_MAX;
    }
}

void dijkstra(int s, int stage) {
    priority_queue<pair<int, int>> pq; // {dist, node}
    pq.push({0, s});
    dist[stage][s] = 0;

    while (!pq.empty()) {
        int cCost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (int i=0;i<graph[cur].size();i++) {
            int next = graph[cur][i].first;
            int nCost = graph[cur][i].second;

            if (dist[stage][next] > cCost + nCost) {
                dist[stage][next] = cCost + nCost;
                pq.push({-dist[stage][next], next});
            }
        }
    }
}

int main() {
    init();

    scanf("%d %d %d %d %d", &C, &P, &PB, &PA1, &PA2);
    for(int i=0;i<C;i++) {
        int P1_i, P2_i, D_i;

        scanf("%d %d %d", &P1_i, &P2_i, &D_i);
        graph[P1_i].push_back({P2_i, D_i});
        graph[P2_i].push_back({P1_i, D_i});
    }

    dijkstra(PB, 0);
    dijkstra(PA1, 1);
    dijkstra(PA2, 2);

    printf("%d", min(dist[0][PA1] + dist[1][PA2], dist[0][PA2] + dist[2][PA1]));

    return (0);
}