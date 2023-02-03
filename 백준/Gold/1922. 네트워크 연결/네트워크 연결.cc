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

using namespace std;

vector<vector<pair<int, int>>> graph(1001);
int N, M;
int a, b, c;
bool visited[1001];

int MST_prim(int s) {
	int ret = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, s });

	while (!pq.empty()) {
		int cur = pq.top().second;
		int cCost = -pq.top().first;
		pq.pop();

		if (!visited[cur]) ret += cCost;
		else continue;

		visited[cur] = true;

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int nCost = graph[cur][i].second;

			if (!visited[next]) {
				pq.push({-nCost, next});
			}
		}
	}

	return ret;
}

int main()
{
	scanf("%d\n%d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}
	
	printf("%d", MST_prim(1));

	return 0;
}