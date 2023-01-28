#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

#define INF 987654321

using namespace std;

int N, M;
int dist[101][101];

int main() {
    scanf("%d\n%d", &N, &M);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dist[i][j] = INF;
        }
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        dist[a][b] = 1;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        int cnt = 0;
        for (int j = 1; j <= N; j++) {
            if (i == j) continue;
            if (dist[i][j] == INF && dist[j][i] == INF) cnt++;
        }
        printf("%d\n", cnt);
    }

    return 0;
}