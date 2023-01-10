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
	long long fib[91] = { 0 };
	int n;

	scanf("%d", &n);

	fib[1] = 1;
	fib[2] = 1;
	for (int i = 3; i <= n; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}

	printf("%lld", fib[n]);


	return 0;
}
