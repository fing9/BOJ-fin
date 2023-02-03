#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>

#define INF 1987654321
#define ll long long
#define SIZE 2097152
#define BASE 1048576

using namespace std;

ll iTree[SIZE];
int N, Q;
int x, y, a, b;

void update(int b, ll c) {
    b += BASE;
    iTree[b] = c;

    while ((b /= 2) > 0) {
        iTree[b] = iTree[b * 2] + iTree[b * 2 + 1];
    }
}

ll query(int s, int e) {
    s += BASE;
    e += BASE;

    ll ret = 0;
    while(s<=e) {
        if(s % 2 == 1) {
            ret += iTree[s++];
        }
        s /= 2;

        if(e % 2 == 0) {
            ret += iTree[e--];
        }
        e /= 2;
    }

    return ret;
}

int main() {
    int tmp;
    scanf("%d\n%d", &N, &Q);

    for (int i = 1; i <= N; i++) {
        scanf("%lld", &iTree[BASE + i]);
    }

    for (int i = BASE - 1; i > 0; i--) {
        iTree[i] = iTree[i*2] + iTree[i*2 + 1];
    }

    for(int i=0;i<Q;i++) {
        scanf("%d %d %d %d", &x, &y, &a, &b);
        if(y < x) {
            tmp = x;
            x = y;
            y = tmp;
        }
        printf("%lld\n", query(x, y));
        update(a, (ll)b);
    }

    return 0;
}