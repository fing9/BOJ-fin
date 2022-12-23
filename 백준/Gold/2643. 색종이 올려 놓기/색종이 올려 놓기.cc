#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

vector<pair<int, int>> v;
int DP[101];
int N, ans = 0;

int main() {
    scanf("%d", &N);

    for(int i=0;i<101;i++) {
        DP[i] = 0;
    }

    for(int i=0;i<N;i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if(a > b) {
            v.push_back({a, b});
        }
        else {
            v.push_back({b, a});
        }
    }
    sort(v.begin(), v.end());

    DP[0] = 1;
    for(int i=0;i<N;i++) {
        for(int j=i-1;j>=0;j--) {
            if(v[j].first <= v[i].first && v[j].second <= v[i].second) {
                DP[i] = max(DP[i], DP[j] + 1);
            }
            else {
                DP[i] = max(DP[i], 1);
            }
        }
        ans = max(ans, DP[i]);
    }

    printf("%d", ans);

    return 0;
}