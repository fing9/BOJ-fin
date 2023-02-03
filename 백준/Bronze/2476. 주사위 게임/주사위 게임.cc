#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define INF 1987654321

using namespace std;

int main() {
    int n, inp, ret, ans = 0;
    vector<int> v;
    
    scanf("%d", &n);
    while(n--) {
        ret = 0;
        
        for(int i=0;i<3;i++) {
            scanf("%d", &inp);
            v.push_back(inp);
        }
        
        sort(v.begin(), v.end());
        
        if(v[0] == v[1] && v[1] == v[2]) {
            ret = 10000 + (v[0] * 1000);
        }
        else if(v[0] == v[1] || v[1] == v[2]) {
            ret = 1000 + (v[1] * 100);
        }
        else {
            ret = v[2] * 100;
        }
        
        ans = max(ans, ret);
        
        v.clear();
    }
    
    printf("%d", ans);
    
    return 0;
}