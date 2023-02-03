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

int graph[401][401];
int dist[401][401];

void init()
{
    for(int i=0;i<401;i++) {
        for(int j=0;j<401;j++) {
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

    int n, k, s;
    scanf("%d %d", &n, &k);
    for(int i=0;i<k;i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        dist[a][b] = 1;
    }

    for(int m=1;m<=n;m++) {
        for(int s=1;s<=n;s++) {
            for(int e=1;e<=n;e++) {
                if(dist[s][e] > dist[s][m] + dist[m][e])
                    dist[s][e] = dist[s][m] + dist[m][e];
            }
        }
    }

    scanf("%d", &s);
    for(int i=0;i<s;i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        if(dist[a][b] == INF && dist[b][a] == INF)
            printf("0\n");
        else if(dist[a][b] == INF && dist[b][a] != INF)
            printf("1\n");
        else if(dist[a][b] != INF && dist[b][a] == INF)
            printf("-1\n");
    }

    return 0;
}