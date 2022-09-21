#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <bitset>

#define INF 987654321

using namespace std;

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
    vector<int> v;
    int n, x, cnt = 0;
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        scanf("%d", &x);
        v.push_back(x);
    }
    scanf("%d", &x);

    sort(v.begin(),v.end());

    int l = 0, r = n-1;
    while(l < r)
    {
        if(v[l] + v[r] == x)
        {
            cnt++;
            l++;
            r--;
        }
        else if(v[l] + v[r] < x)
        {
            l++;
        }
        else
        {
            r--;
        }
    }
    
    printf("%d", cnt);

    return 0;
}