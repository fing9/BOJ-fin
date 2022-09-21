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

int BF[1000001];
int DP[1000001];

void init() {
    for (int i = 0; i < 1000001; i++) {
        DP[i] = INF;
        BF[i] = INF;
    }
    DP[1] = 0;
}

int solve(int N) {

    for(int i=2;i<=N;i++)
    {
        DP[i] = DP[i - 1] + 1;
        BF[i] = i - 1;
        
        if(i%3 == 0)
        {
            if(DP[i] > DP[i/3] + 1)
            {
                DP[i] = DP[i/3] + 1;
                BF[i] = i / 3;
            }
        }
        
        if(i%2 == 0)
        {
            if(DP[i] > DP[i/2] + 1)
            {
                DP[i] = DP[i/2] + 1;
                BF[i] = i / 2;
            }
        }
    }

    return DP[N];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    int X, ret, ori;
    cin >> X;
    ret = solve(X);
    cout << ret << "\n";
    while(X != 1) {
        printf("%d ", X);
        X = BF[X];
    }
    printf("1");

    return 0;
}