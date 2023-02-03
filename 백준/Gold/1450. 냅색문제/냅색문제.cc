#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long ret = 0;
long long N, C;
vector<long long> vN;
vector<long long> vA, vB;

void solve(vector<long long> &v, long long be, long long en, long long now) {
    if(be > en) {
        v.push_back(now);
        return;
    }
    
    if(now + vN[be] <= C)
        solve(v, be + 1, en, now + vN[be]); // 물건을 가방에 넣는다.
    solve(v, be + 1, en, now); // 물건을 가방에 넣지 않는다.
}

int main() {
    scanf("%lld %lld", &N, &C);
    
    for(int i=0;i<N;i++) {
        long long d;
        scanf("%lld", &d);
        vN.push_back(d);
    }
    
    solve(vA, 0, (N/2), 0);
    solve(vB, (N/2)+1, N-1, 0);
    
    sort(vB.begin(), vB.end());
    
    for(int i=0;i<vA.size();i++) {
        //printf("%lld ", vA[i]);
        if(vB[0] + vA[i] <= C)
            ret += upper_bound(vB.begin(), vB.end(), C - vA[i]) - vB.begin();
        else
            ret += 1;
    }
    
    printf("%lld", ret);
    
    return 0;
}