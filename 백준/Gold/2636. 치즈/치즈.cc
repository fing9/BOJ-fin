#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

#define INF 1987654321

using namespace std;

int N, M, curStage = 1;
int direc[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int map[102][102];
int visited[102][102];

bool isIn(int y, int x) {
    if(0<y && y<=N && 0<x && x<=M) return true;
    else return false;
}

int meltdown(int sY, int sX, int stage) {
    queue<pair<int, int>> q;
    int cnt = 0;
    q.push({sY, sX});
    visited[sY][sX] = stage;

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        if(map[cur.first][cur.second] == 1) {
            map[cur.first][cur.second] = 0;
            cnt++;
            continue;
        }

        for(int i=0;i<4;i++) {
            pair<int, int> next = {cur.first + direc[i][0], cur.second + direc[i][1]};

            if(isIn(next.first, next.second) && visited[next.first][next.second] != stage) {
                q.push(next);
                visited[next.first][next.second] = stage;
            }
        }
    }

    return cnt;
}

int main() {
    int cheeses = 0, ret, ans;
    scanf("%d %d", &N, &M);

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++) {
            scanf("%d", &map[i][j]);
            if(map[i][j] == 1) cheeses++;
        }
    }

    while (cheeses > 0) {
        ans = cheeses;
        ret = meltdown(1,1,curStage++);
        cheeses -= ret;
    }

    printf("%d\n%d", curStage-1, ans);

    return 0;
}