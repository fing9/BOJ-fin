#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <cmath>

#define INF 987654321

using namespace std;

int main() {
    vector<pair<int,int>> v;
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=1;i<=n;i++) {
        int inp;
        scanf("%d", &inp);
        v.push_back({inp,i});
    }

    sort(v.begin(),v.end());

    for(int l=0;l<m;l++) {
        int i, j, k;
        scanf("%d %d %d", &i, &j, &k);

        int cnt = 0;
        for(int f=0;f<v.size();f++) {
            if(i <= v[f].second && v[f].second <= j) {
                cnt++;
                if(cnt == k) {
                    printf("%d\n", v[f].first);
                    break;
                }
            }
        }
    }

    return 0;
}
