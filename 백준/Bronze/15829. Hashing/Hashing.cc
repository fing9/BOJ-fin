#include <iostream>
#include <string>
#include <cmath>
#define M 1234567891

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long ans = 0, L, r = 1;
    string str;
    cin >> L;
    cin >> str;
    for(int i=0;i<str.length();i++) {
        ans = (ans + (str[i] - 'a' + 1) * r) % M;
        r = (r * 31) % M;
    }

    cout << ans;

    return 0;
}