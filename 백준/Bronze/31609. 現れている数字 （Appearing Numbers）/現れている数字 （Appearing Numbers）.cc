#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, inp;
    vector<int> v;
    
    scanf("%d", &N);
    for (int i=0;i<N;i++) {
        scanf("%d", &inp);
        v.push_back(inp);
    }
    sort(v.begin(), v.end());
    for (int i=0;i<v.size();i++) {
        if (i == 0 || v[i - 1] != v[i]) {
            printf("%d\n", v[i]);
        }
    }
    
    return 0;
}
