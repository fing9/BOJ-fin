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

vector<vector<int>> graph(10001);
bool visited[10001], isArticulationPoint[10001];
int V, E, orderCnt = 1, cnt = 0;

int dfs(int cur, int prev, int order[], int low[]) {
	visited[cur] = true;
	order[cur] = orderCnt++;

	int child = 0;

	int minOrder = order[cur];
	for (int i = 0; i < graph[cur].size(); i++) {
		int next = graph[cur][i];

		if (next == prev) continue;
		if (visited[next]) {
			minOrder = min(minOrder, order[next]);
		}
		else {
			child++;

			// 다음 노드로 탐색을 한 후, 기존 방문 노드 중 가장 순서가 빠른(작은) 값을 리턴 받기
			low[cur] = dfs(next, cur, order, low);

			if (prev != -1 && low[cur] >= order[cur] && !isArticulationPoint[cur]) {
				cnt++;
				isArticulationPoint[cur] = true;
			}

			minOrder = min(minOrder, low[cur]);
		}
	}

	if (prev == -1 && child >= 2) {
		cnt++;
		isArticulationPoint[cur] = true;
	}

	return minOrder;
}

int main()
{
	scanf("%d %d", &V, &E);

	for (int i = 0; i < E; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= V; i++) {
		if (!visited[i]) {
			int order[10001], low[10001];
			dfs(i, -1, order, low);
		}
	}

	printf("%d\n", cnt);
	for (int i = 1; i <= V; i++) {
		if (isArticulationPoint[i]) {
			printf("%d ", i);
		}
	}

	return 0;
}