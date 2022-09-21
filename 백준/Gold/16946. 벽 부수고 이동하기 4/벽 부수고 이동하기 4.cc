#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <bitset>

//https://www.acmicpc.net/problem/16946

using namespace std;

int N, M;
int matrix[1002][1002];
int cheak[1002][1002];
int gruop[1002][1002];
int di[4][2] = {{-1, 0},
                {0,  -1},
                {1,  0},
                {0,  1}};
queue<pair<int, int>> q, q2;

void init() {
    for (int i = 0; i < 1002; i++) {
        for (int j = 0; j < 1002; j++) {
            matrix[i][j] = 1;
            cheak[i][j] = 0;
            gruop[1002][1002] = 0;
        }
    }
}

void test() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            printf("%d", matrix[i][j]%10);
        }
        if(i != N)
            printf("\n");
    }
}

bool isIn(int y, int x) {
    if (1 <= y && y <= N && 1 <= x && x <= M) return true;
    else return false;
}

void bfs(int y, int x, int l) {
    int cnt = 1;
    q.push({y, x});
    cheak[y][x] = 1;

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q2.push(q.front());
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (isIn(p.first + di[i][0], p.second + di[i][1]) && matrix[p.first + di[i][0]][p.second + di[i][1]] == 0 &&
                cheak[p.first + di[i][0]][p.second + di[i][1]] == 0) {
                q.push({p.first + di[i][0], p.second + di[i][1]});
                cheak[p.first + di[i][0]][p.second + di[i][1]] = 1;
                cnt++;
            }
        }
    }

    while (!q2.empty()) {
        pair<int, int> p = q2.front();
        q2.pop();
        cheak[p.first][p.second] = cnt;
        gruop[p.first][p.second] = l;
    }
}

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    char c;
    map<int, int> m;

    init();

    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%*c");
        for (int j = 1; j <= M; j++) {
            scanf("%c", &c);
            if (c == '1')
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
        }
    }

    int l = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (matrix[i][j] == 0 && cheak[i][j] == 0) {
                bfs(i, j, l++);
            }
        }
    }

    vector<int> v;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (matrix[i][j] == 1) {
                for (int k = 0; k < 4; k++) {
                    bool go = true;
                    for (int s = 0; s < v.size(); s++) {
                        if (v[s] == gruop[i + di[k][0]][j + di[k][1]]) {
                            go = false;
                            break;
                        }
                    }
                    if (go) {
                        matrix[i][j] += cheak[i + di[k][0]][j + di[k][1]];
                        v.push_back(gruop[i + di[k][0]][j + di[k][1]]);
                    }
                }
                v.clear();
            }
        }
    }

    test();

    return 0;
}