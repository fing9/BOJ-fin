#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <cmath>

#define INF 987654321

// MST Prim Algorithm

using namespace std;
int V, E;
vector<pair<int, int>> v[10001];
int visited[10001];

void init() {
    for (int i = 0; i < 10001; i++) {
        visited[i] = 0;
    }
}

long long mst_prim(int s) {
    long long ret = 0;
    priority_queue<pair<int, int>> pq; // pair : {간선의 가중치, 노드 번호}
    pq.push({0, s});

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        //printf("%d %d\n", -pq.top().first, pq.top().second);
        pq.pop();

        if(visited[cur] == 1) continue;
        visited[cur] = 1;
        ret += cost;

        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;
            int nCost = v[cur][i].second;

            if(visited[next] == 0)
                pq.push({-nCost, next});
        }
    }

    return ret;
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    init();

    scanf("%d %d", &V, &E);

    for (int i = 0; i < E; i++) {
        int A, B, C;
        scanf("%d %d %d", &A, &B, &C);
        v[A].push_back({B, C});
        v[B].push_back({A, C});
    }

    printf("%lld", mst_prim(1));

    return 0;
}