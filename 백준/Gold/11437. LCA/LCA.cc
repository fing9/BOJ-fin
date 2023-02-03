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
#define MAXDEPTH 18

using namespace std;

vector<vector<int>> graph(100001);
bool visited[100001];
int parent[100001][18];
int tree[100001];
int depth[100001];
int N, M;

void dfs(int cur, int last, int curDepth) {
	parent[cur][0] = last;
	depth[cur] = curDepth;

	for (int i = 0; i < graph[cur].size(); i++) {
		if (!visited[graph[cur][i]]) {
			visited[graph[cur][i]] = true;
			dfs(graph[cur][i], cur, curDepth + 1);
		}
	}
}

void setParents() {
	for (int i = 1; i < MAXDEPTH; i++) {
		for (int j = 1; j <= N; j++) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
		}
	}
}

int findCoparent(int a, int b) {
	// a >= b 상태로 변경
	if (depth[a] < depth[b]) {
		int tmp = a;
		a = b;
		b = tmp;
	}

	// 높이 맞추기
	if (depth[a] != depth[b]) {
		for (int i = MAXDEPTH - 1; i >= 0; i--) {
			if (depth[parent[a][i]] < depth[b]) continue;
			a = parent[a][i];
		}
	}

	// 예외 : 높이를 맞춰줬더니 둘 중 하나가 부모였던 경우
	if (a == b) return a;

	// 두 노드의 부모가 최초로 같아지기 전까지 탐색
	for (int i = MAXDEPTH - 1; i >= 0; i--) {
		if (parent[a][i] == parent[b][i]) continue;
		
		a = parent[a][i];
		b = parent[b][i];
	}

	return parent[a][0];
}

int main()
{
	int a, b, tmp;
	// initialize
	tree[1] = 1;

	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	visited[1] = true;
	dfs(1, 0, 0);
	depth[0] = -1;

	setParents();

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", findCoparent(a, b));
	}

	return 0;
}