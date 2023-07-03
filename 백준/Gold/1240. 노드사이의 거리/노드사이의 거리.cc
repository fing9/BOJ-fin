#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
vector<vector<pair<int, int> > > graph(1001);
int N, M;

int bfs(int s, int e) {
    int visited[1001][1001];
    queue<pair<int, int> > q;

    q.push(make_pair(s, 0));
    for(int i=0;i<1001;i++) {
        for (int j=0;j<1001;j++) {
            visited[i][j] = 0;
        }
    }
    while(!q.empty()) {
        int cur = q.front().first;
        int cCost = q.front().second;
        q.pop();

        if (cur == e) {
            return cCost;
        }

        for (int i=0;i<graph[cur].size();i++) {
            int next = graph[cur][i].first;
            int nCost = graph[cur][i].second;
            if (visited[cur][next] == 0) {
                visited[cur][next] = 1;
                visited[next][cur] = 1;
                q.push(make_pair(next, cCost + nCost));
            }
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i=0;i<N-1;i++) {
        int a, b, c;

        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }

    for (int i=0;i<M;i++) {
        int a, b;

        scanf("%d %d", &a, &b);
        printf("%d\n", bfs(a, b));
    }

    return 0;
}