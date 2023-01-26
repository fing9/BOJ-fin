#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

#define INF 1987654321

using namespace std;

int N, M;
int dist[201][201];
int ret[201][201];

int main() {
    scanf("%d %d", &N, &M);

    for(int i=0;i<M;i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        dist[a][b] = c;
        dist[b][a] = c;
        ret[a][b] = b;
        ret[b][a] = a;
    }

    for(int k=1;k<=N;k++) {
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=N;j++) {
                if(dist[i][k] == 0 || dist[k][j] == 0) continue;

                if(dist[i][j] > dist[i][k] + dist[k][j] || dist[i][j] == 0) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    ret[i][j] = ret[i][k];
                }
            }
        }
    }

    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            if(i == j) printf("- ");
            else printf("%d ", ret[i][j]);
        }
        printf("\n");
    }

    return 0;
}