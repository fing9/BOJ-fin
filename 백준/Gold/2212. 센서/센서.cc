#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <utility>
#include <queue>
#include <stack>

using namespace std;

int main() {
    vector<int> v, vGap;
    int N, K, ret;

    scanf("%d\n%d", &N, &K);
    K -= 1;

    for(int i=0;i<N;i++) {
        int inp;
        scanf("%d", &inp);
        v.push_back(inp);
    }

    if(N == 1) {
        printf("0");
        return 0;
    }

    sort(v.begin(),v.end());

    ret = v[N-1] - v[0];

    for(int i=0;i<N-1;i++) {
        vGap.push_back(v[i+1] - v[i]);
    }

    sort(vGap.begin(), vGap.end());

    for(int i=N-2;;i--) {
        if(K == 0) break;
        ret -= vGap[i];

        K--;
    }

    printf("%d", ret);

    return 0;
}
