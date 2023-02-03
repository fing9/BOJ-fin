#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long DP[1000002]; // DP[i번째 숫자] = [i,n) 구간의 최대 증가하는 부분수열의 길이
    long long n, inp, ans = 0, now;
    vector<long long> v;
    vector<long long> l;
    vector<long long> lis;

    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &inp);
        v.push_back(inp);
//        printf("%d ", inp);
    }
//    printf("\n");

    for (int i = 0; i <= n; i++) {
        DP[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (l.empty()) {
            l.push_back(v[i]);
            DP[i] = 1;
        } else if (l[l.size() - 1] < v[i]) {
            l.push_back(v[i]);
            DP[i] = l.size();
        } else {
            l[lower_bound(l.begin(), l.end(), v[i]) - l.begin()] = v[i];
            DP[i] = lower_bound(l.begin(), l.end(), v[i]) - l.begin() + 1;
        }
        ans = max(ans, DP[i]);
//        printf("%d ", DP[i]);
    }
//    printf("\n");

    now = ans;
    for (int i = n - 1; i >= 0; i--) {
        if (DP[i] == now) {
            now--;
            lis.push_back(v[i]);
        }
    }

    printf("%d\n", ans);
    for (int i = ans - 1; i >= 0; i--) {
        printf("%d ", lis[i]);
    }

    return 0;
}
