#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>
#define INF 1987654321

using namespace std;

vector<long long> wood;
int N, M;
int s = 0, e = 0;

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		int inp;
		scanf("%lld", &inp);
		wood.push_back(inp);
		e = max(e, inp);
	}

	while (s <= e) {
		long long mid = (s + e) / 2;
		long long sum = 0;

		for (int i = 0; i < N; i++) {
			if (wood[i] > mid) sum += wood[i] - mid;
		}

		if (sum >= M) s = mid + 1;
		else e = mid - 1;
	}

	printf("%lld", s - 1);

	return 0;
}
