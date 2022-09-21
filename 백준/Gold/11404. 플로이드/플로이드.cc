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

int graph[101][101];
int dist[101][101];

void init()
{
    for(int i=0;i<101;i++) {
        for(int j=0;j<101;j++) {
            if(i==j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
            graph[i][j] = -1;
        }
    }
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    init();

    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i=0;i<m;i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a][b] = c;
        if(c < dist[a][b])
            dist[a][b] = c;
    }


    for(int m=1;m<=n;m++) {
        for(int s=1;s<=n;s++) {
            for(int e=1;e<=n;e++) {
                if(dist[s][e] > dist[s][m] + dist[m][e])
                    dist[s][e] = dist[s][m] + dist[m][e];
            }
        }
    }

    for(int i=1;i<=n;i++) {
        for (int j = 1; j <= n; j++) {
            if(dist[i][j] == INF)
                printf("0 ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}