#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#define INF 987654321

using namespace std;

int dist[402][402];

void init()
{
    for(int i=0;i<402;i++) {
        for(int j=0;j<402;j++) {
            if(i==j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    init();

    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=0;i<m;i++) {
        int a, b, d;
        scanf("%d %d %d", &a, &b, &d);
        dist[a][b] = d;
    }

    for(int m=1;m<=n;m++) {
        for(int s=1;s<=n;s++) {
            for(int e=1;e<=n;e++) {
                if(dist[s][e] > dist[s][m] + dist[m][e])
                    dist[s][e] = dist[s][m] + dist[m][e];
            }
        }
    }

    int ret = INF;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(dist[i][j] != INF && dist[j][i] != INF && i != j) {
                ret = min(ret, dist[i][j] + dist[j][i]);
            }
        }
    }

    if(ret != INF)
        printf("%d", ret);
    else
        printf("-1");

    return 0;
}