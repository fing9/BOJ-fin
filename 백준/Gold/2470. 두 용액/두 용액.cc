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

#define INF 1000000000

using namespace std;

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
    vector<int> v;
    int n, x;
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        scanf("%d", &x);
        v.push_back(x);
    }

    sort(v.begin(),v.end());

    int ret1 = INF, ret2 = INF;
    int l = 0, r = n-1;
    while(l < r)
    {
        if(v[l] + v[r] == 0)
        {
            ret1 = v[l];
            ret2 = v[r];
            break;
        }
        else if(v[l] + v[r] < 0)
        {
            if(abs(v[l] + v[r]) < abs(ret1 + ret2))
            {
                ret1 = v[l];
                ret2 = v[r];
            }
            l++;
        }
        else
        {
            if(abs(v[l] + v[r]) < abs(ret1 + ret2))
            {
                ret1 = v[l];
                ret2 = v[r];
            }
            r--;
        }
    }

    printf("%d %d", ret1, ret2);

    return 0;
}