#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

#define INF 1987654321

using namespace std;

int N, M, curStage = 1;
int direc[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
char map[302][302];
int visited[302][302];

bool isIn(int y, int x) {
    if(0<y && y<=N && 0<x && x<=M) return true;
    else return false;
}

bool bfs(int sY, int sX, int stage) {
    queue<pair<int, int>> q;
    q.push({sY, sX});
    visited[sY][sX] = stage;

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();


        if (map[cur.first][cur.second] == '#') {
            return true;
        }
        else if (map[cur.first][cur.second] == '1') {
            map[cur.first][cur.second] = '0';
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

    return false;
}

int main() {
    pair<int,int> startP, endP;
    int y1, x1, y2, x2;
    bool ret = false;
    scanf("%d %d", &N, &M);
    scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
    startP = {y1, x1};
    endP = {y2, x2};

    for(int i=1;i<=N;i++){
        getchar();
        for(int j=1;j<=M;j++) {
            scanf("%c", &map[i][j]);
        }
    }

    while(!ret) {
        ret = bfs(startP.first, startP.second, curStage++);
    }

    printf("%d", curStage - 1);

    return 0;
}