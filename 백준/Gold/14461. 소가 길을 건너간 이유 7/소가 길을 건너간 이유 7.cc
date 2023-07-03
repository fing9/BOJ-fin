#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
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

int N, T;
int map[102][102];
int visited[102][102][4];
int direc[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

bool isIn(int y, int x) {
    return (1 <= y && y <= N && 1 <= x && x <= N);
}

int dijkstra(int sy, int sx) {
    priority_queue<pair<pair<int,int>, pair<int, int>>> pq;
    pq.push({{0,0},{sy,sx}});

    while (!pq.empty()) {
        pair<int,int> cur = pq.top().second;
        int cCost = -pq.top().first.first;
        int nCnt = pq.top().first.second;
        pq.pop();

        if (visited[cur.first][cur.second][nCnt] == 1) continue;
        visited[cur.first][cur.second][nCnt] = 1;
        if (cur.first == N && cur.second == N) return cCost;

        for (int i=0;i<4;i++) {
            pair<int,int> next = {cur.first + direc[i][0], cur.second + direc[i][1]};
            int nCost = T;

            if (!isIn(next.first, next.second)) continue;

            if (nCnt + 1 == 3) { 
                nCost += map[next.first][next.second];
            }

            if (nCnt + 1 == 3)
                pq.push({{-(cCost + nCost), 0}, next});
            else
                pq.push({{-(cCost + nCost), (nCnt + 1)}, next});
        }
    }
}

int main() {
    scanf("%d %d", &N, &T);
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            scanf("%d", &map[i][j]);
        }
    }
    printf("%d\n", dijkstra(1,1));

    return 0;
}