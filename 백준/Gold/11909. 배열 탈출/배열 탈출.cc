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
int N;
int map[2223][2223];
int dist[2223][2223];
int direc[2][2] = {{1,0}, {0,1}};

bool isIn(int y, int x) {
    return (1 <= y && y <= N && 1 <= x && x <= N);
}

void dijkstra(int sy, int sx) {
    priority_queue<pair<int,pair<int,int>>> pq;
    pq.push({0, {sy, sx}});
    dist[sy][sx] = 0;

    while (!pq.empty()){
        pair<int,int> cur = pq.top().second;
        int cCost = -pq.top().first;
        pq.pop();

        for (int i=0;i<2;i++) {
            pair<int,int> next = {cur.first + direc[i][0], cur.second + direc[i][1]};
            if (!isIn(next.first, next.second)) continue;
            int nCost = max(0, map[next.first][next.second] - map[cur.first][cur.second] + 1);

            if (dist[next.first][next.second] > cCost + nCost) {
                dist[next.first][next.second] = cCost + nCost;
                pq.push({-dist[next.first][next.second], next});
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            scanf("%d", &map[i][j]);
            dist[i][j] = MAX;
        }
    }

    dijkstra(1, 1);
    printf("%d", dist[N][N]);
    return 0;
}
