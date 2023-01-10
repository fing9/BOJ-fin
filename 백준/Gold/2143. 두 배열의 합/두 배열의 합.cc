#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>
#define INF 1987654321

using namespace std;

int A[1001], B[1001];
int pSumA[1001], pSumB[1001];
vector<int> partialA, partialB;
int lenA = 1, lenB = 1;

int main()
{
	int T, n, m;
	long long ret = 0;
	int s = 0, e, retValue;
	int lastA = 0;

	scanf("%d\n%d", &T, &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
		pSumA[i] = pSumA[i - 1] + A[i];
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &B[i]);
		pSumB[i] = pSumB[i - 1] + B[i];
	}

	for (int i = 0; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			partialA.push_back(pSumA[j] - pSumA[i]);
		}
	}

	for (int i = 0; i <= m; i++) {
		for (int j = i + 1; j <= m; j++) {
			partialB.push_back(pSumB[j] - pSumB[i]);
		}
	}

	sort(partialA.begin(), partialA.end());
	sort(partialB.begin(), partialB.end());

	lenA = partialA.size();
	lenB = partialB.size();

	//for (int i = 0; i < lenA; i++) {
	//  printf("%d ", partialA[i]);
	//}
	//printf("\n");

	//for (int i = 0; i < lenB; i++) {
	//  printf("%d ", partialB[i]);
	//}
	//printf("\n");

	int pA = 0;
	int pB = lenB - 1;

	while (pA < lenA && pB >= 0) {
		int sum = partialA[pA] + partialB[pB];
		int aTemp = partialA[pA];
		int bTemp = partialB[pB];
		int aCnt = 0;
		int bCnt = 0;

		if (sum == T) {

			while (pA < lenA && partialA[pA] == aTemp) {
				pA++;
				aCnt++;
			}

			while (pB >= 0 && partialB[pB] == bTemp) {
				pB--;
				bCnt++;
			}

			ret += (long long)aCnt * (long long)bCnt;
		}
		else if (sum > T) {
			pB--;
		}
		else {
			pA++;
		}

	}


	printf("%lld", ret);

	return 0;
}