#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
int dp[1000001], idx[1000001], ans = 0;

int main() {
    int n;
    vector<int> v;

    scanf("%d", &n);
    for (int i=0;i<n;i++) {
        int inp;
        scanf("%d", &inp);
        v.push_back(inp);
        idx[inp] = i;
    }
    
    for (int i=n-1;i>=0;i--) {
        dp[i] = 1;
        if (idx[v[i] + 1] > i) {
            dp[i] = dp[idx[v[i] + 1]] + 1;
        }
        ans = max(ans, dp[i]);
    }
    printf("%d", n - ans);

    return 0;
}