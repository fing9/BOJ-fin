#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <cmath>

#define INF 987654321

using namespace std;

long double calc(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    long double ret;

    ret = ((x2-x1)*(y3-y1) - (x3-x1)*(y2-y1)) / 2.0;

    return ret;
}

int main() {
    vector<pair<long long, long long>> v;
    int N;
    double d = 0;

    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        long long x, y;
        scanf("%lld %lld", &x, &y);
        v.push_back({x, y});
    }

    for(int i=0;i<N-2;i++) {
        d += calc(v[0].first, v[0].second, v[i+1].first, v[i+1].second, v[i+2].first, v[i+2].second);
    }

    if(d < 0) d *= -1;
    printf("%.1lf", d);

    return 0;
}