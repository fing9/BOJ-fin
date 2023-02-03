#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string str, ret = "0";
    int num[10] = {0,}, sum = 0;
    cin >> str;

    for(int i=0;i<str.length();i++) {
        num[str[i]-'0']++;
        sum += str[i]-'0';
    }

    if(num[0] == 0 || sum % 3 != 0) {
        printf("-1");
    }
    else {
        num[0]--;
        for(int i=0;i<10;i++) {
            for(int j=0;j<num[i];j++) {
                ret += to_string(i);
            }
        }

        reverse(ret.begin(), ret.end());

        cout << ret;
    }

    return 0;
}