#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <utility>

#define INF 987654321

using namespace std;

int cmds[100002];
int dp[100002][5][5];
int idx = 1;

int calc(int cur, int next) {
    if(cur == 0) {
        if(next == 1) return 2;
        else if(next == 2) return 2;
        else if(next == 3) return 2;
        else if(next == 4) return 2;
    }
    else if(cur == 1) {
        if(next == 1) return 1;
        else if(next == 2) return 3;
        else if(next == 3) return 4;
        else if(next == 4) return 3;
    }
    else if(cur == 2) {
        if(next == 1) return 3;
        else if(next == 2) return 1;
        else if(next == 3) return 3;
        else if(next == 4) return 4;
    }
    else if(cur == 3) {
        if(next == 1) return 4;
        else if(next == 2) return 3;
        else if(next == 3) return 1;
        else if(next == 4) return 3;
    }
    else {
        if(next == 1) return 3;
        else if(next == 2) return 4;
        else if(next == 3) return 3;
        else if(next == 4) return 1;
    }
}

int solve(int cnt, int left, int right) {
    if(dp[cnt][left][right] != INF) return dp[cnt][left][right];
    if(cnt == idx - 1) return 0;

    return dp[cnt][left][right] = min(calc(left, cmds[cnt+1]) + solve(cnt+1, cmds[cnt+1], right), calc(right, cmds[cnt+1]) + solve(cnt+1, left, cmds[cnt+1]));
}

void init() {
    for(int i=0;i<100002;i++) {
        for(int j=0;j<5;j++) {
            dp[i][j][0] = INF;
            dp[i][j][1] = INF;
            dp[i][j][2] = INF;
            dp[i][j][3] = INF;
            dp[i][j][4] = INF;
        }
    }
}

int main() {
    int inp;

    init();

    do {
        scanf("%d", &inp);
        cmds[idx++] = inp;
    } while(inp != 0);
    idx--;

    solve(0, 0, 0);

    printf("%d", dp[0][0][0]);

    return 0;
}