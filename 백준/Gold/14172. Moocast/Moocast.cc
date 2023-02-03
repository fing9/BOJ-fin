#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <queue>

using namespace std;
vector<pair<int, pair<int,int>>> v(201); // vector <power, <x, y>>
double len[201][201]; // len [cur][to] = length
int flag[201] = {0,};
int N, ans = -1;

void init() {
    for(int i=0;i<201;i++) {
        flag[i] = 0;
    }
}

double getLen(int x1, int y1, int x2, int y2) {
    return sqrt(pow((double)abs(x1-x2), 2) + pow((double)abs(y1-y2), 2));
}

int count(int cur) {
    int cnt = 1;

    flag[cur] = 1;
    for(int i=0;i<N;i++) {
        if(len[cur][i] <= v[cur].first && i != cur && flag[i] == 0) {
            flag[i] = 1;
            cnt += count(i);
        }
    }

    return cnt;
}

int main() {
    scanf("%d", &N);

    for(int i=0;i<N;i++) {
        scanf("%d %d %d", &v[i].second.first, &v[i].second.second, &v[i].first);
    }

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            double length = getLen(v[i].second.first, v[i].second.second, v[j].second.first, v[j].second.second);
            len[i][j] = length;
            len[j][i] = length;
            //printf("%lf ", getLen(v[i].second.first, v[i].second.second, v[j].second.first, v[j].second.second));
        }
        //printf("\n");
    }

    for(int i=0;i<N;i++) {
        init();
        //printf("%d ", count(i));
        ans = max(ans, count(i));
    }

    printf("%d", ans);

    return 0;
}