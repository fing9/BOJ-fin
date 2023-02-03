#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

#define INF 1987654321
#define ll long long

using namespace std;

int N, cnt;
ll ans = -1;

void backTracking(ll num, int size)
{
    if(size == 0) {
        if (cnt == N)
            ans = num;
        cnt++;
        return;
    }

    int last = num % 10;
    if(num == 0) last = 10;
    for (int i=0;i<last;i++) {
        ll nextNum = (num * 10) + i;
        if(num == 0 && i == 0) continue;

        backTracking(nextNum, size - 1);
    }
}

void solve() {
    for (int i = 0; i <= 10; i++)
    {
        backTracking(0, i);
    }
}

int main() {
    scanf("%d", &N);

    solve();

    printf("%lld", ans);

    return 0;
}