#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <stack>
#include <queue>
#include <utility>
#include <bitset>
#include <unistd.h>

#define FAST ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define INT_MAX 2147483647
#define LL_MAX 9223372036854775807
#define MAX 1000000001
#define MIN -1000000001
#define ll long long
#define ull unsigned long long
#define GRAPH vector<vector<pair<int, int>>>

using namespace std;
int T, W;
int DP[1002][32][2];
vector<int> v;

void init() {
    for (int i=0;i<1002;i++) {
        for (int j=0;j<32;j++) {
            DP[i][j][0] = -1;
            DP[i][j][1] = -1;
        }
    }
}

int dfs(int t, int w, int cur) {
    if (t - 1 == T) return 0;
    if (w == W) {
        if (v[t] == 1) {
            if (cur == 0)
                return DP[t][w][cur] = dfs(t + 1, w, 0) + 1;
            else
                return DP[t][w][cur] = dfs(t + 1, w, 1);
        }
        else {
            if (cur == 1)
                return DP[t][w][cur] = dfs(t + 1, w, 1) + 1;
            else
                return DP[t][w][cur] = dfs(t + 1, w, 0);
        }
    }
    if (DP[t][w][cur] != -1) {
        return DP[t][w][cur];
    }

    if (v[t] == 1) {
        if (cur == 0)
            return DP[t][w][cur] = max(dfs(t + 1, w, cur) + 1, dfs(t + 1, w + 1, 1));
        else
            return DP[t][w][cur] = max(dfs(t + 1, w, cur), dfs(t + 1, w + 1, 0) + 1);
    }
    else {
        if (cur == 0)
            return DP[t][w][cur] = max(dfs(t + 1, w, cur), dfs(t + 1, w + 1, 1) + 1);
        else
            return DP[t][w][cur] = max(dfs(t + 1, w, cur) + 1, dfs(t + 1, w + 1, 0));
    }
}

int main() {
    init();
    scanf("%d %d", &T, &W);
    v.push_back(0);
    for (int i=0;i<T;i++) {
        int inp;
        scanf("%d", &inp);
        v.push_back(inp);
    }
    dfs(0, 0, 0);
    int ans = 0;
    for (int i=1;i<=T;i++) {
        for (int j=0;j<=W;j++) {
            ans = max(ans, max(DP[i][j][0], DP[i][j][1]));
        }
    }
    printf("%d", ans);

    return 0;
}
