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

int dist[101][101];
pair<int,int> route[101][101];

void init() {
    for(int i=0;i<101;i++) {
        for(int j=0;j<101;j++) {
            dist[i][j] = INF;
            route[i][j] = {i,i};
        }
    }
}

int findRoute(int from, int to, int target) {
    if(target == route[from][to].first) return to;

    return findRoute(from, route[from][to].first, target);
}

void printRoute(int from, int to, vector<int> *v) {
    v->push_back(from);
    //printf("%d ", from);

    if(from == to) return;
    printRoute(route[from][to].second, to, v);
    return;
}

int main() {

    init();

    int n, m;
    scanf("%d\n%d", &n, &m);

    for(int i=0;i<m;i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if(dist[a][b] > c) {
            dist[a][b] = c;
            route[a][b].second = b;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if(i == j) {
                    dist[i][j] = 0;
                    continue;
                }
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    route[i][j].second = findRoute(route[i][k].first, route[i][k].second, i);
                    route[i][k].first = i;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(dist[i][j] != INF) printf("%d ", dist[i][j]);
            else printf("0 ");
        }
        printf("\n");
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(dist[i][j] != INF && i!=j) {
                vector<int> v;
                printRoute(i, j, &v);
                printf("%d ", v.size());
                for(int i=0;i<v.size();i++) {
                    printf("%d ", v[i]);
                }
            }
            else printf("0");
            printf("\n");
        }
    }

    return 0;
}