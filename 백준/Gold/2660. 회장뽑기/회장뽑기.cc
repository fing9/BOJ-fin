#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <utility>
#include <bitset>

#define FAST ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define INT_MAX 2147483647
#define LL_MAX 9223372036854775807
#define MAX 987654321
#define MIN -987654321
#define ll long long
#define GRAPH vector<vector<pair<int, int>>>

using namespace std;

int N, ansDistArr[51], ansDist = MAX, ansN = 0;
int dist[51][51];

void init() {
    for (int i = 0; i < 51; i++) {
        ansDistArr[i] = 0;
        for (int j = 0; j < 51; j++) {
            dist[i][j] = MAX;
            if (i == j)
                dist[i][j] = 0;
        }
    }
}

int main() {
    init();

    scanf("%d", &N);
    while (1) {
        int a, b;

        scanf("%d %d", &a, &b);
        if (a == -1 && b == -1)
            break;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (dist[i][j] < MAX)
                ansDistArr[i] = max(ansDistArr[i], dist[i][j]);
        }
        ansDist = min(ansDist, ansDistArr[i]);
    }

    for (int i = 1; i <= N; i++) {
        if (ansDistArr[i] == ansDist)
            ansN++;
    }

    printf("%d %d\n", ansDist, ansN);

    for (int i = 1; i <= N; i++) {
        if (ansDistArr[i] == ansDist)
            printf("%d ", i);
    }

    return (0);
}