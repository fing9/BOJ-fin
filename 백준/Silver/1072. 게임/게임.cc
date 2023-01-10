#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>
#define INF 1987654321

using namespace std;

int main()
{
	long long X, Y, Z, curZ, ans = -1;
	scanf("%lld %lld", &X, &Y);
	Z = (Y * 100) / X;

	// 99% 이상은 값이 변하지 않는다.
	if (Z >= 99) {
		printf("-1");
		return 0;
	}

	int s = 1, e = 1000000000, mid;

	while (s <= e) {
		mid = (s + e) / 2;

		curZ = ((Y + mid) * 100) / (X + mid);

		if (Z < curZ) {
			e = mid - 1;
			ans = mid;
		}
		else {
			s = mid + 1;
		}
	}

	printf("%lld", ans);

	return 0;
}