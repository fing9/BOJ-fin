#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>
#include <deque>
#include <set>
#include <map>
#define INF 1987654321
#define ll long long

using namespace std;

int N, M;
bool visited[10];
vector<int> v;

void dfs(vector<int> numbers, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", numbers[i]);
		}
		printf("\n");
		return;
	}

	int prev = 0;
	for (int i = 0; i < N; i++) {
		if (!visited[i] && prev != v[i]) {
			visited[i] = true;
			numbers.push_back(v[i]);
			prev = v[i];
			dfs(numbers, cnt + 1);
			numbers.pop_back();
			visited[i] = false;
		}
	} 
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		int inp;
		scanf("%d", &inp);
		v.push_back(inp);
	}
	sort(v.begin(), v.end());

	vector<int> rets;
	dfs(rets, 0);

	return 0;
}