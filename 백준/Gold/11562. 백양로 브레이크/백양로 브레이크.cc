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
int N, M, K;
int graph[252][252];

void init() {
    for(int i=0;i<252;i++) {
        for(int j=0;j<252;j++) {
            graph[i][j] = INF;
            if(i == j) graph[i][j] = 0;
        }
    }
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
    init();

    scanf("%d %d", &N, &M);

    for(int i=0;i<M;i++) {
        int u, v, b;
        scanf("%d %d %d", &u, &v, &b);
        if(b == 0) {
            graph[u][v] = 0;
            graph[v][u] = 1;
        }
        else {
            graph[u][v] = 0;
            graph[v][u] = 0;
        }
    };

    //floyd
    for(int l = 1; l <= N; l++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (graph[i][l] + graph[l][j] < graph[i][j]) {
                    graph[i][j] = graph[i][l] + graph[l][j];
                }
            }
        }
    }

    scanf("%d", &K);

    for(int i=0;i<K;i++) {
        int s, e;
        scanf("%d %d", &s, &e);

        printf("%d\n", graph[s][e]);
    }

    return 0;
}
