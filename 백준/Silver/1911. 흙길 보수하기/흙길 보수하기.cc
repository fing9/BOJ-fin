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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<pair<int,int>> v;
    int N, L, p = 0, cnt = 0;
    cin >> N >> L;

    for(int i=0;i<N;i++) {
        int s, e;
        cin >> s >> e;
        v.push_back({s,e-1});
        //cout << "s:" << s << " e:" << e-1 << "\n";
    }

    sort(v.begin(), v.end());
    
    for(int i=0;i<N;i++) {
        if(p < v[i].first)
            p = v[i].first;
        else if(p > v[i].second)
            continue;
        while(v[i].first <= p && p <= v[i].second) {
            p += L;
            //cout << p << ",";
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}