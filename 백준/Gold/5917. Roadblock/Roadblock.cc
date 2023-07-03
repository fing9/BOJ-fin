#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <utility>
#include <bitset>
#include <unistd.h>

#define FAST ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define INT_MAX 2147483647
#define LL_MAX 9223372036854775807
#define MAX 1000000001
#define MIN -1000000001
#define ll long long
#define ull unsigned long long
#define GRAPH vector<vector<pair<int, int>>>

using namespace std;

GRAPH graph(101);
int dist[101], visited[101][101];
int N, M, shortestDist, ans = 0;

void init() {
    for (int i=0;i<101;i++) {
        dist[i] = MAX;
    }
}

void dijkstra(int s) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, s});
    dist[s] = 0;

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

void visitedEdge(int cur, int cCost) {
    for(int i=0;i<graph[cur].size();i++) {
        int next = graph[cur][i].first;
        int nCost = graph[cur][i].second;

        if (dist[next] == cCost + nCost && visited[cur][next] == 0) {
            visited[cur][next] = 1;
            visited[next][cur] = 1;
            visitedEdge(next, dist[next]);
        }
    }
}

int main() {
    init();

    scanf("%d %d", &N, &M);
    for (int i=0;i<M;i++) {
        int a, b, c;

        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    dijkstra(1);
    visitedEdge(1, 0);

    shortestDist = dist[N];

    for (int i=1;i<=N;i++) {
        for(int j=0;j<graph[i].size();j++) {
            if (visited[i][graph[i][j].first] == 1) {
                init();
                graph[i][j].second *= 2;
                dijkstra(1);
                ans = max(ans, dist[N] - shortestDist);
                graph[i][j].second /= 2;
            }
        }
    }

    printf("%d", ans);

    return (0);
}