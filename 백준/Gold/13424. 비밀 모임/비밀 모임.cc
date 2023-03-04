#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

#define INF 987654321

using namespace std;

int dist[101][101];

void init() {
    for(int i=0;i<101;i++) {
        for(int j=0;j<101;j++) {
            dist[i][j] = INF;
            if (i == j)
                dist[i][j] = 0;
        }
    }
}

int main() {
    int T;

    scanf("%d", &T);
    while (T--) {
        int N, M, K;
        int ret = INF, ans = 0;
        vector<int> v;

        init();
        scanf("%d %d", &N, &M);
        for(int i=0;i<M;i++) {
            int a, b, c;

            scanf("%d %d %d", &a, &b, &c);
            dist[a][b] = c;
            dist[b][a] = c;
        }

        for(int k=1;k<=N;k++) {
            for(int i=1;i<=N;i++) {
                for(int j=1;j<=N;j++) {
                    if (dist[i][j] > dist[i][k] + dist[k][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }

        scanf("%d", &K);
        for(int k=0;k<K;k++) {
            int s;

            scanf("%d", &s);
            v.push_back(s);
        }

        for (int i=1;i<=N;i++) {
            int sum = 0;

            for (int j=0;j<v.size();j++) {
                sum += dist[i][v[j]];
            }
            if (ret > sum) {
                ret = sum;
                ans = i;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}