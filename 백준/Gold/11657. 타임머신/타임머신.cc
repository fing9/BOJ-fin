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
#define INF 1987654321
#define ll long long

using namespace std;

vector<vector<pair<int, int>>> graph(501);
ll dist[501];
int N, M;
int u, v, w;

bool bellman_ford(int s) {
	dist[s] = 0;

	for (int t = 1; t <= N - 1; t++) {
		for (int i = 1; i <= N; i++) {
			int cur = i;
			for (int j = 0; j < graph[i].size(); j++) {
				int next = graph[i][j].first;
				int nCost = graph[i][j].second;

				if (dist[cur] != INF && dist[next] > dist[cur] + nCost)
					dist[next] = dist[cur] + nCost;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		int cur = i;
		for (int j = 0; j < graph[i].size(); j++) {
			int next = graph[i][j].first;
			int nCost = graph[i][j].second;

			if (dist[cur] != INF && dist[next] > dist[cur] + nCost)
				return true;
		}
	}

	return false;
}

void init() {
	for (int i = 0; i < 501; i++) {
		dist[i] = INF;
	}
}

int main()
{
	init();

	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &u, &v, &w);
		graph[u].push_back({ v, w });
	}

	if (bellman_ford(1)) {
		printf("-1");
		return 0;
	}

	for (int i = 2; i <= N; i++) {
		if (dist[i] == INF) printf("-1\n");
		else printf("%lld\n", dist[i]);
	}


	return 0;
}