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

int main()
{
	vector<int> v, fromBottom, fromTop;
	int pSum[500001] = {0,};
	int N, H, inp, cntB, cntT, ret = INF, retCnt = 0;
	int lo = 0, hi = 0;

	scanf("%d %d", &N, &H);
	for (int i = 0; i < N; i++) {
		scanf("%d", &inp);
		if (i % 2 == 0) {
			fromBottom.push_back(inp);
		}
		else {
			fromTop.push_back(inp);
		}
		hi = max(hi, inp);
	}
	N /= 2;

	sort(fromBottom.begin(), fromBottom.end());
	sort(fromTop.begin(), fromTop.end());

	// 매번 이분탐색으로 카운팅

	for (int i = 1; i <= H; i++) {
		cntB = N - (upper_bound(fromBottom.begin(), fromBottom.end(), i - 1) - fromBottom.begin());
		cntT = N - (lower_bound(fromTop.begin(), fromTop.end(), H - i + 1) - fromTop.begin());

		if (ret == cntB + cntT) {
			retCnt++;
		}
		else if (ret > cntB + cntT) {
			ret = cntB + cntT;
			retCnt = 1;
		}
	}

	printf("%d %d", ret, retCnt);

	return 0;
}