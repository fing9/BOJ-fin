#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#define INF 1987654321

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    int num[5002];
    int DP[5002];

    for(int i=0;i<5002;i++) {
        DP[i] = 0;
    }

    cin >> str;

    for(int i=1;i<=str.length();i++) {
        num[i] = str[i-1] - '0';
    }

    if(str.length() == 1) {
        if(num[1] == 0)
            printf("0");
        else
            printf("1");
        return 0;
    }

    DP[0] = 1;
    for(int i=1;i<=str.length();i++) {
        if(num[i] != 0) {
            DP[i] = (DP[i] + DP[i-1]) % 1000000;
        }

        if(i==1) continue;
        int x = num[i] + (num[i-1] * 10);

        if(10<=x && x<=26) {
            DP[i] = (DP[i] + DP[i-2]) % 1000000;
        }
    }

    printf("%d", DP[str.length()]);

    return 0;
}