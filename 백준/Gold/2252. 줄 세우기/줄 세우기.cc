#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cmath>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <deque>
#define INF 1987654321

using namespace std;

vector<vector<int>> graph(32001);
vector<int> ret;
int visited[32001];
bool parent[32001];
int n, m;
int a, b;

void dfs(int s) {
	for (int i = 0; i < graph[s].size(); i++) {
		int next = graph[s][i];

		if (visited[next] == 0) {
			visited[next] = 1;
			dfs(next);
		}
	}

	ret.push_back(s);
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		graph[b].push_back(a);
		parent[a] = true;
	}
	
	for (int i = 1; i <= n; i++) {
		if(!parent[i] && visited[i] == 0) dfs(i);
	}

	for (int i = 0; i < ret.size(); i++) {
		printf("%d ", ret[i]);
	}

	return 0;
}