#include <iostream>


using namespace std;

int main()
{
	int pSum[10001] = { 0, };
	int N, M, ret = 0;
	int s = 0, e = 1;

	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		int inp;
		scanf("%d", &inp);
		pSum[i] += pSum[i - 1] + inp;
	}

	while (s<=N && e<=N) {
		int sum = pSum[e] - pSum[s];

		if (sum == M) {
			ret++;
			e++;
		}
		else if (sum < M) {
			e++;
		}
		else {
			s++;
		}
	}

	printf("%d", ret);

	return 0;
}
