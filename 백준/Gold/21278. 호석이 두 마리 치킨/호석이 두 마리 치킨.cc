#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

#define INF 987654321

using namespace std;

int dist[101][101];
int ret;

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        dist[a][b] = 1;
        dist[b][a] = 1;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == k || j == k) continue;
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    int ansA, ansB, ansDist = INF;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            int ret = 0;
            if (i == j) continue;

            for(int k=1;k<=n;k++) {
                if (dist[i][k] != INF && dist[j][k] != INF)
                {
                    if (dist[i][k] < dist[j][k])
                        ret += dist[i][k];
                    else
                        ret += dist[j][k];
                }
                else if(dist[i][k] != INF) {
                    ret += dist[i][k];
                }
                else if(dist[j][k] != INF) {
                    ret += dist[j][k];
                }
            }

            if (ansDist > ret) {
                ansDist = ret;
                ansA = i;
                ansB = j;
            }
        }
    }

    if (ansA < ansB)
        printf("%d %d %d", ansA, ansB, ansDist*2);
    else
        printf("%d %d %d", ansB, ansA, ansDist*2);

    return 0;
}