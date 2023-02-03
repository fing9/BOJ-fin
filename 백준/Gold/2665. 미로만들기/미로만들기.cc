#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

#define INF 987654321

using namespace std;

int graph[52][52];
int dist[52][52];
int direc[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int n;

bool isIn(int y, int x) {
    if(1 <= y && y <= n && 1 <= x && x <= n) return true;
    else return false;
}

void dijkstra(int sy, int sx) {
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {sy, sx}});

    while(!pq.empty()) {
        pair<int,int> cur = pq.top().second;
        int cCost = -pq.top().first;
        pq.pop();

        for(int i=0;i<4;i++) {
            pair<int,int> next = {cur.first + direc[i][0], cur.second + direc[i][1]};
            int nCost = graph[next.first][next.second];

            if (isIn(next.first, next.second) && dist[next.first][next.second] > cCost + nCost) {
                dist[next.first][next.second] = cCost + nCost;
                pq.push({-dist[next.first][next.second], next});
            }
        }
    }
}

void init() {
    for(int i=0;i<52;i++) {
        for(int j=0;j<52;j++) {
            dist[i][j] = INF;
        }
    }
}

int main() {
    init();

    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        getchar();
        for(int j=1;j<=n;j++) {
            char inp;
            scanf("%c", &inp);
            if(inp == '1') graph[i][j] = 0;
            else graph[i][j] = 1;
        }
    }

    dijkstra(1, 1);

    printf("%d", dist[n][n]);

    return 0;
}