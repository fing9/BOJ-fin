#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

#define INF 987654321

using namespace std;

int dist[202][202];

int main() {
    int N, M;

    scanf("%d\n%d", &N, &M);
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            int inp;

            scanf("%d", &inp);
            if (inp == 1)
                dist[i][j] = 1;
            else
                dist[i][j] = INF;
        }
    }

    for (int k=1;k<=N;k++) {
        for (int i=1;i<=N;i++) {
            for (int j=1;j<=N;j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    for (int i=1;i<=N;i++) {
        dist[i][i] = 1;
    }

    int from, to = 1;
    for (int i=1;i<=M;i++) {
        from = to;
        scanf("%d", &to);

        if (i == 1)
            continue;
        if (dist[from][to] == INF) {
            printf("NO");
            return 0;
        }
    }

    printf("YES");

    return 0;
}