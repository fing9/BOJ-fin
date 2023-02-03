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
int N, K, cheak[100001] = {0,}, route[100001] = {0,}, nowR = INF;
queue<pair<int,int>> q;
vector<int> v;

bool isIn(int n) {
    if(0 <= n && n <= 100000) return true;
    else return false;
}

int bfs(int s) {
    q.push({s, 0});
    cheak[s] = 1;
    route[s] = s;

    while(!q.empty()) {
        int pNow = q.front().first;
        int pTime = q.front().second;
        q.pop();

        if(pNow > nowR) continue;

        if(pNow == K) {
            if(nowR > pNow) nowR = pNow;
            return pTime;
        }

        if(isIn(pNow - 1)) {
            if (cheak[pNow - 1] == 0) {
                q.push({pNow - 1, pTime + 1});
                cheak[pNow - 1] = 1;
                route[pNow - 1] = pNow;
            }
        }

        if(isIn(pNow + 1)) {
            if (cheak[pNow + 1] == 0) {
                q.push({pNow + 1, pTime + 1});
                cheak[pNow + 1] = 1;
                route[pNow + 1] = pNow;
            }
        }

        if(isIn(pNow * 2)) {
            if (cheak[pNow * 2] == 0) {
                q.push({pNow * 2, pTime + 1});
                cheak[pNow * 2] = 1;
                route[pNow * 2] = pNow;
            }
        }
    }
}


int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    scanf("%d %d" , &N, &K);

    printf("%d\n", bfs(N));

    v.push_back(K);

    int now = K;
    while(1) {
        if(now == N) break;
        else {
            v.push_back(route[now]);
            now = route[now];
        }
    }

    for(int i=v.size()-1;i>=0;i--) {
        printf("%d ", v[i]);
    }

    return 0;
}