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

int gcd(int a, int b) {
	int tmp;
	if (a < b) {
		tmp = b;
		b = a;
		a = tmp;
	}
	
	if (a % b == 0) return b;
	else return gcd(b, a%b);
}

void calc(int x1, int y1, int x2, int y2) {
	int x, y, ret;

	x = (x1 * y2) + (x2 * y1);
	y = (y1 * y2);

	while ((ret = gcd(x,y)) > 1) {
		x /= ret;
		y /= ret;
	}
	
	printf("%d %d", x, y);
}

int main()
{
	int A, B, C, D;
	scanf("%d %d\n%d %d", &A, &B, &C, &D);

	calc(A, B, C, D);

	return 0;
}