#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <string.h>

#define INF 987654321
#define ll long long

using namespace std;

ll gcd(ll a, ll b) {
    if (a < b) {
        ll tmp = a;
        a = b;
        b = tmp;
    }
    if (a % b == 0)
        return (b);
    else
        return gcd(b, a % b);
}

int main() {
    int n;
    ll ans = 0;
    vector<ll> dist, v;

    scanf("%d", &n);
    for (int i=0;i<n;i++) {
        ll inp;
        scanf("%lld", &inp);
        v.push_back(inp);
    }
    ll ret = abs(v[1] - v[0]);
    for (int i=2;i<v.size();i++) {
        ret = gcd(ret, abs(v[i] - v[i - 1]));
    }
    for (int i=1;i<v.size();i++) {
        ans += ((v[i] - v[i - 1]) / ret) - 1;
    }
    printf("%lld", ans);
    return (0);
}