#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <string>

using namespace std;
int V;
int visited[100001] = {0,};
int ans = 0, vN;
vector<vector<pair<int,int>>> v(100001);

void init() {
    for(int i=0;i<100001;i++) {
        visited[i] = 0;
    }
    ans = 0;
}

void dfs(int s, int cost) {
    visited[s] = 1;

    for(int i=0;i<v[s].size();i++) {
        pair<int,int> to = v[s][i];
        if(visited[to.first] == 0) {
            visited[to.first] = 1;
            dfs(to.first, cost + to.second);
        }
    }

    if(ans < cost) {
        ans = cost;
        vN = s;
    }
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
    scanf("%d", &V);

    for(int i=1;i<=V;i++) {
        int now, a, b, inp = 0;
        scanf("%d", &now);
        while(inp != -1) {
            scanf("%d", &inp);
            a = inp;
            if(inp == -1) break;
            scanf("%d", &inp);
            b = inp;
            v[now].push_back({a,b});
        }
    }

    dfs(v[1][0].first,v[1][0].second);
    init();
    dfs(vN, 0);

    printf("%d", ans);


    return 0;
}