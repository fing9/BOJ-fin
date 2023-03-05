#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

#define INF 987654321

using namespace std;

int map[102][102];
int visited[102][102];
int exposed[102][102];
int direc[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int N, M;

void init() {
    for (int i=0;i<102;i++) {
        for (int j=0;j<102;j++) {
            map[i][j] = 0;
            visited[i][j] = 0;
            exposed[i][j] = 0;
        }
    }
}

int isIn(int y, int x) {
    if (1 <= y && y <= N && 1 <= x && x <= M)
        return (1);
    else
        return (0);
}

int meltdown(int y, int x) {
    queue<pair<int,int>> q;
    int cnt = 0;
    q.push({y, x});

    while (!q.empty()) {
        pair<int,int> cur = q.front();
        q.pop();

        for (int i=0;i<4;i++) {
            pair<int,int> next = {cur.first + direc[i][0], cur.second + direc[i][1]};

            if (map[next.first][next.second]) {
                exposed[next.first][next.second]++;
                continue ;
            }
            if (isIn(next.first, next.second) && visited[next.first][next.second] == 0 && map[next.first][next.second] == 0) {
                visited[next.first][next.second] = 1;
                q.push({next.first, next.second});
            }
        }
    }

    for (int i=1;i<=N;i++) {
        for (int j=1;j<=M;j++) {
            if (exposed[i][j] >= 2) {
                map[i][j] = 0;
                cnt++;
            }
            exposed[i][j] = 0;
            visited[i][j] = 0;
        }
    }
    return (cnt);
}

int main() {
    int ans = 0;
    init();

    scanf("%d %d", &N, &M);
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=M;j++) {
            scanf("%d", &map[i][j]);
        }
    }

    while (meltdown(1, 1) > 0) {
        ans++;
    }

    printf("%d", ans);

    return 0;
}