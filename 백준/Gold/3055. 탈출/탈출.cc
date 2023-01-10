#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>
#include <deque>
#define INF 1987654321

using namespace std;

int R, C;
char map[53][53];
int visited[53][53];
int floodMap[53][53];
int dr[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
pair<int, int> dP, sP;

bool isIn(int y, int x) {
    if(0<y && y<=R && 0<x && x<=C) return true;
    else return false;
}

void floodBfs(int y, int x) {
    queue<pair<pair<int, int>,int>> q;
    q.push({{y, x}, 0});
    floodMap[y][x] = 1;

    while(!q.empty()) {
        pair<int,int> pop = q.front().first;
        int curLevel = q.front().second + 1;
        q.pop();

        for(int i=0;i<4;i++) {
            int nextY = pop.first + dr[i][0];
            int nextX = pop.second + dr[i][1];

            if(((curLevel < floodMap[nextY][nextX]) || (floodMap[nextY][nextX] == 0)) && (map[nextY][nextX] != 'X') && (map[nextY][nextX] != 'D') && isIn(nextY, nextX)) {
                q.push({{nextY, nextX}, curLevel});
                floodMap[nextY][nextX] = curLevel;
            }
        }
    }
}

void bfs(int y, int x) {
    queue<pair<pair<int, int>,int>> q;
    q.push({{y, x}, 0});
    visited[y][x] = 1;

    while(!q.empty()) {
        pair<int,int> pop = q.front().first;
        int curLevel = q.front().second + 1;
        q.pop();

        for(int i=0;i<4;i++) {
            int nextY = pop.first + dr[i][0];
            int nextX = pop.second + dr[i][1];

            if(((curLevel < floodMap[nextY][nextX]) || (floodMap[nextY][nextX] == 0)) && (map[nextY][nextX] != 'X') && isIn(nextY, nextX) && visited[nextY][nextX] == 0) {
                q.push({{nextY, nextX}, curLevel});
                visited[nextY][nextX] = curLevel;
            }
        }
    }
}

int main()
{
    scanf("%d %d", &R, &C);

    for(int i=1;i<=R;i++) {
        getchar();
        for(int j=1;j<=C;j++) {
            scanf("%c", &map[i][j]);
            floodMap[i][j] = 0;

            if(map[i][j] == 'D') {
                dP.first = i;
                dP.second = j;
            }
            else if(map[i][j] == 'S') {
                sP.first = i;
                sP.second = j;
            }
        }
    }

    for(int i=1;i<=R;i++) {
        for (int j = 1; j <= C; j++) {
            if(map[i][j] == '*')
                floodBfs(i,j);
        }
    }

    bfs(sP.first, sP.second);

    if(visited[dP.first][dP.second] == 0) printf("KAKTUS");
    else printf("%d", visited[dP.first][dP.second]);

    return 0;
}