#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>
#define INF 1987654321

using namespace std;

vector<int> pSum(100001);
int N, S, ret = INF;
int s=0, e=1;

int main()
{
	scanf("%d %d", &N, &S);

	for (int i = 1; i <= N; i++) {
		int inp;
		scanf("%d", &inp);

		pSum[i] = pSum[i - 1] + inp;
	}

	while (s<=N && e<=N) {
		int sum = pSum[e] - pSum[s];

		if (sum >= S) {
			ret = min(ret, e - s);
			s++;
		}
		else {
			e++;
		}
	}

	if (ret == INF) printf("0");
	else printf("%d", ret);

	return 0;
}
