#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <cmath>

#define INF 987654321

using namespace std;
int mapArr[108] = {0,}, ret = INF;
int countD[108] = {0,};
queue<pair<int,int>> q; //노드번호 탐색횟수

void bfs() {
    q.push({1,0});

    while(!q.empty()) {
        pair<int,int> cur = q.front();
        q.pop();

        if(countD[cur.first] < cur.second) continue;
        else countD[cur.first] = cur.second;

        if(cur.first == 100) {
            ret = min(ret, cur.second);
            continue;
        }

        if(mapArr[cur.first] != 0) {
            q.push({mapArr[cur.first], cur.second});
            continue;
        }

        for(int i=1;i<=6;i++) {
            if(cur.first + i <= 100) {
                q.push({cur.first + i, cur.second + 1});
            }
        }
    }
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    for(int i=0;i<108;i++)
        countD[i] = INF;

    int N, M;
    scanf("%d %d", &N, &M);
    for(int i=0;i<N + M;i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        mapArr[from] = to;
    }

    bfs();

    printf("%d", ret);

    return 0;
}