#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int main() {
    queue<pair<int,int>> q;
    vector<int> ret(1001);
    vector<int> v;
    int N, inp, cnt = 0;
    pair<int, int> p;

    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        scanf("%d", &inp);
        v.push_back(inp);
        q.push({inp, i});
    }

    while(!q.empty()) {
        cnt++;
        p = q.front();
        q.pop();

        if(p.first == 1) {
            ret[p.second] = cnt;
        }
        else {
            q.push({p.first-1, p.second});
        }
    }

    for(int i=0;i<N;i++) {
        printf("%d ", ret[i]);
    }

    return 0;
}