#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;
vector<string> nhear, nsee, v;
int N, M, ret=0;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    
    nhear.resize(N);
    nsee.resize(M);
    for(int i=0;i<N;i++) {
        cin >> nhear[i];
    }
    for(int i=0;i<M;i++) {
        cin >> nsee[i];
    }
    
    sort(nhear.begin(), nhear.end());
    sort(nsee.begin(), nsee.end());
    
    for(int i=0;i<N;i++) {
        if(binary_search(nsee.begin(), nsee.end(), nhear[i])) {
            v.push_back(nhear[i]);
            ret++;
        }
    }
    
    sort(v.begin(), v.end());
    
    cout << ret << "\n";
    
    for(int i=0;i<v.size();i++) {
        cout << v[i] << "\n";
    }
    
    return 0;
}