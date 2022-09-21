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
int N, M;
vector<int> v[1001];
int visited[1001];

void init() {
    for (int i = 0; i < 1001; i++) {
        visited[i] = 0;
    }
}

int mst_prim(int s) {
    int ret = -1;
    priority_queue<pair<int, int>> pq; // pair : {간선의 가중치, 노드 번호}
    pq.push({0, s});

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        //printf("%d %d\n", -pq.top().first, pq.top().second);
        pq.pop();

        if(visited[cur] == 1) continue;
        visited[cur] = 1;
        ret = max(ret, cost);

        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i];
            int nCost = cost + 1;

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

    int t;
    scanf("%d", &t);

    while(t--) {
        init();

        scanf("%d %d", &N, &M);
        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            v[A].push_back(B);
            v[B].push_back(A);
        }

        printf("%d\n", N-1);
        
        //printf("%d\n", mst_prim(1));
    }

    return 0;
}