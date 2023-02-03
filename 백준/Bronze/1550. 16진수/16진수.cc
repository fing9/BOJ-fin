#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

char str[7];
int len, ans, ret, cnt;

int main() {
    scanf("%s", str);
    len = strlen(str);

    for(int i=len-1;i>=0;i--) {
        if('0' <= str[i] && str[i] <= '9') {
            ret = str[i] - '0';
        }
        else {
            ret = 10 + str[i] - 'A';
        }

        for(int j=0;j<cnt;j++) {
            ret *= 16;
        }
        cnt++;
        ans += ret;
    }

    printf("%d", ans);

    return 0;
}