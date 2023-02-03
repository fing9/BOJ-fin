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

int v[1000001];

int Find(int x) {
	if (v[x] == x) return x;
	else return v[x] = Find(v[x]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a == b) return;
	else v[a] = v[b];
}

bool isUnion(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a == b) return true;
	else return false;
}

void init() {
	for (int i = 0; i < 1000001; i++) {
		v[i] = i;
	}
}

int main()
{
	int n, m;
	int cmd, a, b;

	init();

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &cmd, &a, &b);
		if (cmd == 0) {
			Union(a, b);
		}
		else if (cmd == 1) {
			// find
			if (isUnion(a, b)) printf("YES\n");
			else printf("NO\n");
		}
	}

	return 0;
}