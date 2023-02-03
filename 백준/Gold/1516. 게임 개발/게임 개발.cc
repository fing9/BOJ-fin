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

vector<vector<int>> graph(501); // 먼저 지어야 할 건물의 번호
int cost[501];
int N, ret[501];
int inp;

void solve(int s) {
	queue<pair<int, int>> q; // {지금 번호, 짓는데 걸리는 누적 시간}
	ret[s] = max(ret[s], cost[s]);
	q.push({ s, ret[s] });

	while (!q.empty()) {
		int cur = q.front().first;
		int cCost = q.front().second;
		q.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			int prev = graph[cur][i];

			if (ret[cur] < ret[prev] + cost[cur]) {
				ret[cur] = ret[prev] + cost[cur];
				q.push({ prev, ret[prev] });
			}
		}
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		ret[i] = 0;
	}

	for (int i = 1; i <= N; i++) {
		bool flag = false;
		while (1) {
			scanf("%d", &inp);
			if (!flag) {
				cost[i] = inp;
				flag = true;
				continue;
			}
			if (inp == -1) break;

			graph[i].push_back(inp);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			solve(j);
		}
	}

	for (int i = 1; i <= N; i++) {
		printf("%d\n", ret[i]);
	}


	return 0;
}