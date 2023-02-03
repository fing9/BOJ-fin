#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>

#define INF 1987654321

using namespace std;

int N, M;
int map[52][52];
int dist[52][52][2501];
int direc[4][2] = {{1,  0},
                   {0,  1},
                   {-1, 0},
                   {0,  -1}};
vector<pair<int, int>> chicken;
vector<pair<int, int>> home;
vector<int> pick;
int ans = INF, cnt = 0;

int getMinChickenDist(int y, int x) {
    int ret = INF;

    for (int i = 0; i < pick.size(); i++) {
        ret = min(ret, dist[y][x][pick[i]]);
    }

    return ret;
}

bool isIn(int y, int x) {
    if (1 <= y && y <= N && 1 <= x && x <= N) return true;
    else return false;
}

void bfs(int sy, int sx, int stage) {
    bool visited[52][52];
    queue<pair<int, pair<int, int>>> q;

    // initialize
    for(int i=0;i<52;i++) {
        for(int j=0;j<52;j++) {
            visited[i][j] = false;
        }
    }

    q.push({0, {sy, sx}});
    visited[sy][sx] = true;
    dist[sy][sx][stage] = 0;

    while (!q.empty()) {
        pair<int, int> cur = q.front().second;
        int cCost = q.front().first;
        dist[cur.first][cur.second][stage] = cCost;
        q.pop();

        for (int i = 0; i < 4; i++) {
            pair<int, int> next = {cur.first + direc[i][0], cur.second + direc[i][1]};
            int nCost = cCost + 1;

            if (isIn(next.first, next.second) && !visited[next.first][next.second]) {
                visited[next.first][next.second] = true;
                q.push({nCost, next});
            }
        }
    }
}

void init() {
    for (int i = 0; i < 52; i++) {
        for (int j = 0; j < 52; j++) {
            for (int k = 0; k < 2501; k++) {
                dist[i][j][k] = INF;
            }
        }
    }
}

// cnt : 지금까지 뽑은 치킨집의 갯수
void comb(int index, int cnt) {
    // 기저 조건
    if (cnt >= M) {
        int sum = 0;

        for(int i=0;i<home.size();i++) {
            sum += getMinChickenDist(home[i].first, home[i].second);
        }

        ans = min(ans, sum);
        return;
    }

    for (int i = index; i < chicken.size(); i++) {
        pick.push_back(i);
        comb(i + 1, cnt + 1);
        pick.pop_back();
    }
}


int main() {

    init();

    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 1) {
                home.push_back({i, j});
            } else if (map[i][j] == 2) {
                chicken.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < chicken.size(); i++) {
        bfs(chicken[i].first, chicken[i].second, i);
    }

    comb(0, 0);

    printf("%d", ans);

    return 0;
}