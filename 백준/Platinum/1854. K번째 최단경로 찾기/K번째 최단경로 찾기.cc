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

using namespace std;

vector<vector<pair<int, int>>> graph(1001);
priority_queue<int> dist[1001];
int n, m, k;
int a, b, c;

void dijkstra(int s) {
	priority_queue<pair<int, int>> pq; // {1번 노드부터 다음 노드까지의 최단 거리, 다음 노드}
	pq.push({0, s});
	dist[s].push(0);

	while (!pq.empty()) {
		int cur = pq.top().second;
		int cCost = -pq.top().first;
		pq.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int nCost = graph[cur][i].second;

			if (dist[next].size() < k) {
				dist[next].push(cCost + nCost);
				pq.push({ -(cCost + nCost), next });
			}
			else if (dist[next].top() > cCost + nCost) {
				dist[next].pop();
				dist[next].push(cCost + nCost);
				pq.push({ -(cCost + nCost), next });
			}
		}
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back({ b, c });
	}

	dijkstra(1);

	for (int i = 1; i <= n; i++) {
		if (dist[i].size() != k) printf("-1\n");
		else printf("%d\n", dist[i].top());
	}

	return 0;
}