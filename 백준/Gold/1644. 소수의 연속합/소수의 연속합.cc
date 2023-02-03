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
	vector<long long> arr;
	vector<long long> v, sum;
	int n;
	int cnt = 0;

	arr.push_back(0);
	arr.push_back(1);
	v.push_back(0);
	sum.push_back(0);
	scanf("%d", &n);

	for (long long i = 2; i <= n; i++) {
		arr.push_back(i);
	}

	for (long long i = 2; i <= n; i++) {
		if (arr[i] == 0)
			continue;

		for (long long j = i * i; j <= n; j += i) {
			arr[j] = 0;
		}
	}

	for (long long i = 2; i <= n; i++) {
		if (arr[i] != 0) {
			v.push_back(i);
			sum.push_back(i + sum.back());
		}
	}

	int l = 0, r = 1;
	while (r < v.size()) {
		if (sum[r] - sum[l] == n) {
			//printf("%lld - %lld = %d\n", sum[r], sum[l], n);
			cnt++;
			r++;
		}
		else if (sum[r] - sum[l] < n) {
			r++;
		}
		else {
			if (l < r)
				l++;
			else
				r++;
		}
	}

	printf("%d", cnt);

	return 0;
}