#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <string.h>

#define INF 987654321
#define ll long long

using namespace std;

int n, m;
int direc[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int map[502][502];
int visited[502][502];

int bfs(int y, int x) {
    queue<pair<int,int>> q;
    int cnt = 0;
    q.push({y, x});
    visited[y][x] = 1;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        cnt++;

        for (int i=0;i<4;i++) {
            if (map[cur.first + direc[i][0]][cur.second + direc[i][1]] == 1 && visited[cur.first + direc[i][0]][cur.second + direc[i][1]] == 0) {
                visited[cur.first + direc[i][0]][cur.second + direc[i][1]] = 1;
                q.push({cur.first + direc[i][0], cur.second + direc[i][1]});
            }
        }
    }
    return (cnt);
}


int main() {
    int cnt = 0;
    int ans = 0;

    scanf("%d %d", &n, &m);
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            scanf("%d", &map[i][j]);
        }
    }

    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (map[i][j] == 1 && visited[i][j] == 0) {
                cnt++;
                ans = max(ans, bfs(i, j));
            }
        }
    }

    printf("%d\n%d", cnt, ans);
    return (0);
}