#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
    vector<int> v;
    int n, k, x;
    
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++) {
        scanf("%d", &x);
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    
    printf("%d", v[v.size()-k]);
    
    
    return 0;
}