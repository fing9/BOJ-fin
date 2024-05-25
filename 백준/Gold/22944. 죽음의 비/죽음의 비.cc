#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int direc[4][2] = {{1,  0},
                   {0,  1},
                   {-1, 0},
                   {0,  -1}};
int N, H, D;
char mp[502][502];
int visited[502][502][3];
pair<int, int> S;

bool canGo(pair<int, int> next, int nextMove, int nextH, int nextD) {
    return (0 < next.first && next.first <= N && 0 < next.second && next.second <= N &&
            (visited[next.first][next.second][0] > nextMove ||
            visited[next.first][next.second][1] + visited[next.first][next.second][2] < nextH + nextD));
}

int bfs() {
    int ret = 2147483647;
    queue<pair<pair<pair<pair<int, int>, int>, int>, int>> pq; // pair<int,int> cur, int move, int curH, int curD
    pq.push({{{{S.first, S.second}, 0}, H}, 0});
    visited[S.first][S.second][0] = 0;
    visited[S.first][S.second][1] = H;
    visited[S.first][S.second][2] = 0;

    while (!pq.empty()) {
        pair<int, int> cur = pq.front().first.first.first;
        int curMove = pq.front().first.first.second;
        int curH = pq.front().first.second;
        int curD = pq.front().second;
        pq.pop();

        if (mp[cur.first][cur.second] == 'E') {
            ret = min(ret, curMove);
            continue;
        }

        for (int i = 0; i < 4; i++) {
            pair<int, int> next = {cur.first + direc[i][0], cur.second + direc[i][1]};
            int nextH;
            int nextD;

            if (mp[next.first][next.second] == 'U') {
                nextD = D - 1;
                nextH = curH;
            } else if (curD > 0) {
                nextD = curD - 1;
                nextH = curH;
            } else {
                if (curH <= 1) {
                    if (mp[next.first][next.second] != 'E') {
                        continue;
                    } else {
                        nextD = curD;
                        nextH = curH;
                    }
                } else {
                    nextD = 0;
                    nextH = curH - 1;
                }
            }

            if (canGo(next, curMove + 1, nextH, nextD)) {
                if (mp[next.first][next.second] == 'E') {
                    pq.push({{{next, curMove + 1}, nextH}, nextD});
                    visited[next.first][next.second][0] = curMove + 1;
                    visited[next.first][next.second][1] = nextH;
                    visited[next.first][next.second][2] = nextD;
                    continue;
                }

                pq.push({{{next, curMove + 1}, nextH}, nextD});
                visited[next.first][next.second][0] = curMove + 1;
                visited[next.first][next.second][1] = nextH;
                visited[next.first][next.second][2] = nextD;
            }
        }
    }

    if (ret == 2147483647) {
        return -1;
    }
    return ret;
}

int main() {

    scanf("%d %d %d", &N, &H, &D);
    for (int i = 1; i <= N; i++) {
        scanf("%*c");
        for (int j = 1; j <= N; j++) {
            scanf("%c", &mp[i][j]);
            if (mp[i][j] == 'S') {
                S = {i, j};
            }
            visited[i][j][0] = 2147483647;
            visited[i][j][1] = 0;
            visited[i][j][2] = 0;
        }
    }
    printf("%d", bfs());

    return 0;
}
