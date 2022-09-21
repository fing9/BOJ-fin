#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    vector<pair<int, int>> v, vB;
    int N;
    int P[52];
    scanf("%d", &N);
    
    for(int i=0;i<N;i++) {
        int d;
        scanf("%d", &d);
        v.push_back({d, i});
    }
    
    sort(v.begin(),v.end());
    
    for(int i=0;i<N;i++) {
        vB.push_back({v[i].second,i});
    }
    
    sort(vB.begin(),vB.end());
    
    for(int i=0;i<N;i++) {
        printf("%d ", vB[i].second);
    }
    
    return 0;
}