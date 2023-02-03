#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <bitset>

#define INF 987654321

using namespace std;
int N, M, R, cnt = 0;
vector<vector<int>> graph(100001);
int visited[100001] = {0,};
queue<int> q;

void bfs() {
    q.push(R);
    visited[R] = ++cnt;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < graph[cur].size(); i++) {
            if (visited[graph[cur][i]] == 0) {
                q.push(graph[cur][i]);
                visited[graph[cur][i]] = ++cnt;
            }
        }
    }
}

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    int u, v;

    scanf("%d %d %d", &N, &M, &R);

    for (int i = 0; i < M; i++) {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
        //reverse(graph[i].begin(),graph[i].end());
    }

    visited[R] = 1;
    bfs();

    for (int i = 1; i <= N; i++) {
        printf("%d\n", visited[i]);
    }

    return 0;
}