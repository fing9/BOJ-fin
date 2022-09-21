#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str, ret = "";
    int n, i;
    cin >> str;

    while(str.length() % 3 != 0) {
        str = '0' + str;
    }

    n = str.length();
    for(i=n-1;i>=2;i-=3) {
        ret += '0' + ((str[i] - '0') + ((str[i-1] - '0') * 2) + ((str[i-2] - '0') * 4));
    }

    reverse(ret.begin(), ret.end());

    cout << ret;

    return 0;
}