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
int N, d, DP[1002] = {0,};
vector<int> ans;
vector<int> v;

int main() {
    scanf("%d", &N);

    for(int i=0;i<N;i++) {
        scanf("%d", &d);
        v.push_back(d);
    }

    for(int i=0;i<N;i++) {
        int len = 0;
        for(int j=0;j<=i;j++) {
            if(v[j] < v[i]) {
                len = max(DP[j], len);
            }
            DP[i] = len + 1;
        }
    }

    int maxL = -1, maxP = -1;
    for(int i=0;i<N;i++) {
        if(maxL < DP[i]) {
            maxL = DP[i];
            maxP = i;
        }
    }

    int nowL = maxL, nowP = maxP;
    for(int i=nowP;i>=0;i--) {
        if(DP[i] == nowL) {
            ans.push_back(v[i]);
            nowL--;
            nowP = i;
        }
    }

    printf("%d\n", maxL);
    for(int i=ans.size()-1;i>=0;i--) {
        printf("%d ", ans[i]);
    }

    return 0;
}
