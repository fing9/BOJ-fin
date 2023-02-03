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

int pSum[1001];
int N, C;

int GCD(int a, int b) {
	int tmp;
	if (a < b) {
		tmp = a;
		a = b;
		b = tmp;
	}

	if (a % b == 0) return b;
	return GCD(b, a % b);
}

int main()
{
	scanf("%d", &C);

	pSum[1] = 3;
	for (int k = 2; k <= 1000; k++) {
		int cnt = 0;
		for (int i = 1; i < k; i++) {
			if (GCD(k, i) == 1) {
				cnt++;
			}
		}
		cnt *= 2;
		pSum[k] = pSum[k - 1] + cnt;
	}

	while (C--) {
		scanf("%d", &N);

		printf("%d\n", pSum[N]);
	}

	return 0;
}