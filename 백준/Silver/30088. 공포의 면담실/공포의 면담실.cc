#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int N;
vector<long long> v, pSum;

int main() {
    scanf("%d", &N);
    for (int i=0;i<N;i++) {
        int M;
        long long sum = 0;
        scanf("%d", &M);
        for (int j=0;j<M;j++) {
            int time;

            scanf("%lld", &time);
            sum += time;
        }
        v.push_back(sum);
    }

    sort(v.begin(), v.end());
    pSum.push_back(v[0]);
    for (int i=1;i<N;i++) {
        pSum.push_back(pSum[i - 1] + v[i]);
    }
    long long ans = 0;
    for (int i=0;i<N;i++) {
        ans += pSum[i];
    }
    printf("%lld", ans);

    return 0;
}