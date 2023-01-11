#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <deque>
#define INF 1987654321

using namespace std;

int N, M, K;
long long tree[4000001];
long long v[4000001];

long long init(int id, int start, int end) {
	int mid = (start + end) / 2;
	if (start == end) return tree[id] = v[start];
	else return tree[id] = init(id * 2, start, mid) + init(id * 2 + 1, mid + 1, end);
}

void update(int id, int start, int end, int index, long long differ) {
	int mid = (start + end) / 2;
	if (start > index || end < index) return;
	tree[id] += differ;
	if (start != end) {
		update(id * 2, start, mid, index, differ);
		update(id * 2 + 1, mid + 1, end, index, differ);
	}
}

long long sum(int id, int start, int end, int left, int right) {
	int mid = (start + end) / 2;
	if (end < left || right < start) return 0;
	if (left <= start && end <= right) return tree[id];
	return sum(id * 2, start, mid, left, right) + sum(id * 2 + 1, mid + 1, end, left, right);
}

int main()
{
	int a, b;
	long long c;
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; i++)
		scanf("%lld", &v[i]);
	
	init(1, 1, N);

	for (int i = 1; i <= M + K; i++) {
		scanf("%d %d %lld", &a, &b, &c);
		if (a == 1) {
			update(1, 1, N, b, c - v[b]);
			v[b] = c;
		}
		else {
			printf("%lld\n", sum(1, 1, N, b, (int)c));
		}
	}

	return 0;
}