#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <bitset>
#define INF 987654321

using namespace std;
int sum[100001] = {0,};
int ret = -1987654321;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;

    cin >> N >> K;

    for(int i=1;i<=N;i++)
    {
        int num;
        cin >> num;
        sum[i] = num + sum[i-1];
    }

    for(int i=0;i<=N - K;i++)
    {
        if (sum[i + K] - sum[i]) {
            ret = max(sum[i + K] - sum[i], ret);
        }
    }

    cout << ret;

    return 0;
}