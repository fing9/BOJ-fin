#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

int t, n;
int sy, sx, ey, ex;
bool visited[104];
vector<pair<int, int>> graph;

int calc(int y1, int x1, int y2, int x2) {
    return abs(y1-y2) + abs(x1-x2);
}

bool canGo(int y1, int x1, int y2, int x2) {
    if(calc(y1, x1, y2, x2) <= 1000) return true;
    else return false;
}

void bfs() {
    queue<pair<int, int>> q;
    q.push({sy, sx});
    visited[0] = true;

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for(int i=0;i<graph.size();i++) {
            if(canGo(cur.first, cur.second, graph[i].first, graph[i].second) && !visited[i]) {
                q.push(graph[i]);
                visited[i] = true;
            }
        }
    }
}

int main() {
    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);

        memset(visited, 0, sizeof(bool) * 104);
        graph.clear();
        scanf("%d %d", &sy, &sx);
        graph.push_back({sy, sx});
        for(int i=1;i<=n;i++) {
            int y, x;
            scanf("%d %d", &y, &x);
            graph.push_back({y, x});
        }
        scanf("%d %d", &ey, &ex);
        graph.push_back({ey, ex});

        bfs();

        if(visited[n+1]) printf("happy\n");
        else printf("sad\n");
    }
    
    return 0;
}