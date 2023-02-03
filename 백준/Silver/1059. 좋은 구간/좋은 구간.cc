#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector<int> v;
    int l, n, ret = 0;
    cin >> l;
    v.push_back(0);
    for(int i=0;i<l;i++) {
        int inp;
        cin >> inp;
        v.push_back(inp);
    }
    cin >> n;
    l++;
    
    sort(v.begin(), v.end());
    
    for(int i=1;i<l;i++) {
        if(v[i] == n) break;
        if(v[i] > n) {
            if(v[i] - v[i-1] > 1)
            	ret = (v[i] - n) * (n - v[i-1]) - 1;
            break;
        }
    }
    cout << ret;
    
    return 0;
}