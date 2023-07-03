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
int T;
int N, K, W, ans;
vector<vector<int>> v(1001);
int cost[1001];
int DP[1001];

int dfs(int cur) {
    int max_time = 0;
    for (int i=0;i<v[cur].size();i++) {
        int next = v[cur][i];

        if (DP[next] != MAX) {
            max_time = max(max_time, DP[next]);
        }
        else {
            DP[next] = dfs(next);
            max_time = max(max_time, DP[next]);
        }
    }

    return DP[cur] = max_time + cost[cur];
}

void init() {
    for (int i=0;i<1001;i++) {
        DP[i] = MAX;
        v[i].clear();
    }
    ans = MAX;
}

int main() {
    scanf("%d", &T);

    while (T--) {
        init();

        scanf("%d %d", &N, &K);
        for (int i=1;i<=N;i++) {
            scanf("%d", &cost[i]);
        }
        for (int i=0;i<K;i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            v[b].push_back(a);
        }
        scanf("%d", &W);
        dfs(W);
        printf("%d\n", DP[W]);
    }

    return 0;
}
