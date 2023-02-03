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

vector<vector<int>> graph(100001);
bool visited[100001];
vector<pair<int, int>> isArticulationEdge;
int V, E, orderCnt = 1;

int dfs(int cur, int prev, int order[], int low[]) {
	visited[cur] = true;
	order[cur] = orderCnt++;

	int minOrder = order[cur];
	for (int i = 0; i < graph[cur].size(); i++) {
		int next = graph[cur][i];

		// 이미 지난 길은 가지 않는다.
		if (next == prev) continue;

		if (visited[next]) {
			minOrder = min(minOrder, order[next]);
		}
		else {
			// 다음 노드로 탐색을 한 후, 기존 방문 노드 중 가장 순서가 빠른(작은) 값을 리턴 받기
			low[cur] = dfs(next, cur, order, low);

			// 역전이 불가능한 경우 단절선
			if (low[cur] > order[cur]) {
				if(next < cur) isArticulationEdge.push_back({ next, cur });
				else isArticulationEdge.push_back({ cur, next });
			}

			minOrder = min(minOrder, low[cur]);
		}
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
			int order[100001], low[100001];
			dfs(i, 0, order, low);
		}
	}

	sort(isArticulationEdge.begin(), isArticulationEdge.end());

	printf("%d\n", isArticulationEdge.size());
	for (int i = 0; i < isArticulationEdge.size(); i++) {
		printf("%d %d\n", isArticulationEdge[i].first, isArticulationEdge[i].second);
	}

	return 0;
}