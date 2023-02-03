#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

#define INF 1987654321

using namespace std;

int N, inp, k = 1, ans;
vector<int> v;

int main() {
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        scanf("%d", &inp);
        v.push_back(inp);
    }

    sort(v.begin(), v.end(), greater<>());

    for(int i=0;i<v.size();i++) {
        ans = max(ans, v[i] * k);
        k++;
    }

    printf("%d", ans);

    return 0;
}