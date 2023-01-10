#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>
#define INF 1987654321

using namespace std;

long long A[4001], B[4001], C[4001], D[4001];
vector<long long> AB, CD;
int n;
long long ret;

long long BinarySearch(int value) {
	long long lo = 0, hi = CD.size(), mid;
	long long retLo, retHi;

	while (lo < hi) {
		mid = (lo + hi) / 2;

		if (AB[mid] < value) {
			lo = mid + 1;
		}
		else {
			hi = mid;
		}
	}
	retLo = hi;

	lo = 0; hi = CD.size();
	while (lo < hi) {
		mid = (lo + hi) / 2;

		if (AB[mid] <= value) {
			lo = mid + 1;
		}
		else {
			hi = mid;
		}
	}
	retHi = lo;

	return retHi - retLo;
}

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%lld %lld %lld %lld", &A[i], &B[i], &C[i], &D[i]);
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			AB.push_back(-(A[i] + B[j]));
			CD.push_back(C[i] + D[j]);
		}
	}

	sort(AB.begin(), AB.end());
	sort(CD.begin(), CD.end());

	for (int i = 0; i < CD.size(); i++) {
		ret += BinarySearch(CD[i]);
	}

	printf("%lld", ret);

	return 0;
}