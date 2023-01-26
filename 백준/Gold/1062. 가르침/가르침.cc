#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <utility>
#include <complex>

using namespace std;

char str[51][16];
bool isAlpha[27];
int N, K, ans = 0;

void counting() {
    int cnt, len, ret = 0;

    for(int j=0;j<N;j++) {
        len = strlen(str[j]);
        cnt = 0;

        for(int k=0;k<len;k++) {
            if(isAlpha[str[j][k] - 'a']) cnt++;
        }

        if(cnt == len) ret++;
    }

    ans = max(ans, ret);
}

void pickup(int cur, int cnt) {
    if(cnt == K) {
        counting();
        return;
    }

    for(int i=cur;i<26;i++) {
        if (i == 0 || i == 2 || i == 8 || i == 13 || i == 19) continue;
        isAlpha[i] = true;
        pickup(i+1, cnt+1);
        isAlpha[i] = false;
    }
}

int main() {
    scanf("%d %d", &N, &K);

    for(int i=0;i<N;i++) {
        scanf("%*c%s", &str[i]);
    }

    if(K < 5) {
        printf("0");
        return 0;
    }


    isAlpha[0] = true;
    isAlpha[2] = true;
    isAlpha[8] = true;
    isAlpha[13] = true;
    isAlpha[19] = true;
    pickup(0, 5);

    printf("%d", ans);

    return 0;
}