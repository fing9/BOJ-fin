#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

#define INF 987654321

using namespace std;

int item[101];
int dist[101][101];
int n, m, r;
int ans;

int main() {
    scanf("%d %d %d", &n, &m, &r);
    for(int i=1;i<=n;i++) {
        scanf("%d", &item[i]);
        for(int j=1;j<=n;j++) {
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    for(int i=0;i<r;i++) {
        int a, b, d;
        scanf("%d %d %d", &a, &b, &d);
        dist[a][b] = d;
        dist[b][a] = d;
    }

    for(int k=1;k<=n;k++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    for(int i=1;i<=n;i++) {
        int ret = 0;
        for(int j=1;j<=n;j++) {
            if (dist[i][j] != INF && dist[i][j] <= m) {
                ret += item[j];
            }
        }
        ans = max(ans, ret);
    }

    printf("%d", ans);

    return 0;
}