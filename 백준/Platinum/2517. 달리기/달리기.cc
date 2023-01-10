#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>
#define INF 1987654321

using namespace std;

// 구간합 인덱스 트리
int indexTree[1100000];
vector<pair<int,int>> v;
int N, origin;
int rankAr[500001];

int getLog(int num) {
	int cnt = 1;

	while (num > 0) {
		cnt *= 2;
		num /= 2;
	}

	return cnt;
}

void edit(int id, int value) {
	while (id > 0) {
		indexTree[id] += value;
		id /= 2;
	}
}

int sum(int s, int e) {
	int l = s + origin - 1;
	int r = e + origin - 1;
	int ret = 0;

	while (l <= r) {
		if (l % 2 == 1) {
			ret += indexTree[l];
		}

		if (r % 2 == 0) {
			ret += indexTree[r];
		}

		l = (l + 1) / 2;
		r = (r - 1) / 2;
	}

	return ret;
}

int main()
{
	scanf("%d", &N);

	origin = getLog(N);

	for (int i = 0; i < N; i++) {
		int inp;
		scanf("%d", &inp);
		v.push_back({ inp, i + 1 });
	}

	sort(v.begin(), v.end(), greater<>());

	for (int i = 0; i < N; i++) {
		int cur = v[i].second;

		edit(origin + cur - 1, 1);
		rankAr[cur] = sum(1, cur);
	}


	for (int i = 1; i <= N; i++) {
		printf("%d\n", rankAr[i]);
	}


	return 0;
}