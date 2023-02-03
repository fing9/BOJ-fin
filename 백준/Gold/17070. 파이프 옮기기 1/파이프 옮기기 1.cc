#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define DIV 1999

using namespace std;

int N, ans;
int DP[18][18];
int map[18][18];

void init();

int solve(int y, int x, int last) {
//    if(DP[y][x] != -1) return DP[y][x];
    if(y == N && x == N) return DP[y][x] = 1;

    int ret = 0;
    if(map[y][x+1] == 0 && last != 2) ret += solve(y, x+1, 1);
    if(map[y+1][x] == 0 && last != 1) ret += solve(y+1, x, 2);
    if((map[y+1][x] == 0) && (map[y][x+1] == 0) && (map[y+1][x+1] == 0)) ret += solve(y+1, x+1, 3);

    return DP[y][x] = ret;
}

int main() {
    scanf("%d", &N);

    for(int i=0;i<=N+1;i++) {
        for(int j=0;j<=N+1;j++) {
            map[i][j] = -1;
        }
    }

    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            scanf("%d", &map[i][j]);
        }
    }

    init();
    solve(1, 2, 1);

//    for(int i=1;i<=N;i++) {
//        for(int j=1;j<=N;j++) {
//            printf("%d ", DP[i][j]);
//        }
//        printf("\n");
//    }

    ans = DP[1][2];

    printf("%d", ans);

    return 0;
}

void init() {
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 18; j++) {
            DP[i][j] = -1;
        }
    }
}