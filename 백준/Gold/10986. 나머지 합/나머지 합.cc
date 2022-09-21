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

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
    long long sum[1000002] = {0,};
    long long cntDiv[100002] = {0,};
    long long N, M, cnt = 0;

    scanf("%lld %lld", &N, &M);

    for(int i=1;i<=N;i++) {
        long long num;
        scanf("%lld", &num);
        num %= M;
        sum[i] = (sum[i-1] + num) % M;
        if(sum[i] == 0) {
            cnt++;
        }
        cntDiv[sum[i]]++;
    }

    for(int i=0;i<=M;i++) {
        cnt += (cntDiv[i] * (cntDiv[i] - 1)) / 2;
    }

    printf("%lld", cnt);

    return 0;
}