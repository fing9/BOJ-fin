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
int N, K, cheak[100001] = {0,}, cheak2[100001] = {0,}, ret = INF, retN = 0;
queue<pair<int,int>> q;

bool isIn(int n) {
    if(0 <= n && n <= 100000) return true;
    else return false;
}

void bfs(int s) {
    q.push({s, 0});
    cheak[s] = 1;

    while(!q.empty()) {
        int pNow = q.front().first;
        int pTime = q.front().second;
        q.pop();

        if(pTime > ret) continue;
        cheak[K] = 0;

        if(pNow == K) {
            if(ret > pTime) {
                ret = pTime;
                retN = 1;
            }
            else if(ret == pTime) {
                retN++;
            }
        }

        if(isIn(pNow - 1)) {
            if (cheak[pNow - 1] == 0 || (cheak2[pNow - 1] >= pTime + 1)) {
                q.push({pNow - 1, pTime + 1});
                cheak[pNow - 1] = 1;
                cheak2[pNow - 1] = pTime + 1;
            }
        }

        if(isIn(pNow + 1)) {
            if (cheak[pNow + 1] == 0 || (cheak2[pNow + 1] >= pTime + 1)) {
                q.push({pNow + 1, pTime + 1});
                cheak[pNow + 1] = 1;
                cheak2[pNow + 1] = pTime + 1;
            }
        }

        if(isIn(pNow * 2)) {
            if (cheak[pNow * 2] == 0 || (cheak2[pNow * 2] >= pTime + 1)) {
                q.push({pNow * 2, pTime + 1});
                cheak[pNow * 2] = 1;
                cheak2[pNow * 2] = pTime + 1;
            }
        }
    }
}


int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    scanf("%d %d" , &N, &K);

    bfs(N);

    printf("%d\n%d", ret, retN);

    return 0;
}