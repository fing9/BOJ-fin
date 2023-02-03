#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cmath>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <deque>
#define INF 987654321
#define ll long long

using namespace std;

int dist[101][101];
int N, M;
int u, v, w;

void init() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			dist[i][j] = INF;
		}
	}
}

int main()
{
	init();

	scanf("%d\n%d", &N, &M);

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &u, &v, &w);
		if (dist[u][v] != INF) {
			if (dist[u][v] > w) {
				dist[u][v] = w;
			}
		}
		else {
			dist[u][v] = w;
		}
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j) continue;

				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dist[i][j] == INF) printf("0 ");
			else printf("%d ", dist[i][j]);
		}
		printf("\n");
	}

	return 0;
}