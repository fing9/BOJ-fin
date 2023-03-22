#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <string.h>

#define INF 987654321
#define ll long long

using namespace std;

int main() {
    pair<int, int> p1 = {-10000, -10000}, p2 = {10000, 10000};
    int n;

    scanf("%d", &n);
    for (int i=0;i<n;i++) {
        int y, x;
        scanf("%d %d", &y, &x);
        if (y > p1.first)
            p1.first = y;
        if (x > p1.second)
            p1.second = x;
        if (y < p2.first)
            p2.first = y;
        if (x < p2.second)
            p2.second = x;
    }

    printf("%d", abs(p1.first - p2.first) * abs(p1.second - p2.second));
}