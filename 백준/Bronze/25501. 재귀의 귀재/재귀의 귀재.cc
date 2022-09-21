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
int ret = 0;

int recursion(const char *s, int l, int r){
    ret++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;

    while(t--) {
        char s[1001];
        ret = 0;
        cin >> s;

        cout << isPalindrome(s) << " " << ret << "\n";

    }

    return 0;
}

