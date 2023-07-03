#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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

int dist[202][202];

void init() {
    for (int i = 0; i < 202; i++) {
        for (int j = 0; j < 202; j++) {
            dist[i][j] = MAX;
            if (i == j)
                dist[i][j] = 0;
        }
    }
}

int main() {
    int N, M, ans = 1;
    int ansMax = MAX;

    init();

    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int a, b, c;

        scanf("%d %d %d", &a, &b, &c);
        if (dist[a][b] > c)
            dist[a][b] = c;
        if (dist[b][a] > c)
            dist[b][a] = c;
    }

    // 플로이드-워셜
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        int sum = 0;
        for (int j = 1; j <= N; j++) {
            sum += dist[i][j];
        }
        if ((ansMax > sum) || (ansMax == sum && ans > i)) {
            ansMax = sum;
            ans = i;
        }
    }

    printf("%d", ans);

    return (0);
}