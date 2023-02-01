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

bool test(ll num) {
    ll first, last = -1;

    while(num > 0) {
        if(last != -1 && last+1 != num % 10) return false;
        last = num % 10;
        num /= 10;
    }

    if(last == 9) return true;
    else return true;
}

void makeNum(ll num, int size) {
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

        makeNum(nextNum, size - 1);
    }
}

void backTracking() {
    for (int i = 0; i <= 10; i++)
    {
        makeNum(0, i);
    }
}

int main() {
    scanf("%d", &N);

    backTracking();

    printf("%lld", ans);

    return 0;
}