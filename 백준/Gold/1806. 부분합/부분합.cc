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

#define INF 1000000001

using namespace std;

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
    vector<int> v;
    int n, s, x;
    scanf("%d %d", &n, &s);
    v.push_back(0);
    for(int i=1;i<=n;i++) {
        scanf("%d", &x);
        v.push_back(x + v[i-1]);
        //printf("%d ", v[i]);
    }
    //printf("\n");

    int ret = INF;
    int l = 0, r = 1;
    while(r < n+1)
    {
        if(v[r] - v[l] == s)
        {
            if(ret > r - l)
                ret = r - l;
            r++;
        }
        else if(v[r] - v[l] < s)
        {
            r++;
        }
        else
        {
            if(ret > r - l)
                ret = r - l;
            if(l < r)
                l++;
            else
                r++;
        }
    }

    if(ret != INF)
        printf("%d", ret);
    else
        printf("0");

    return 0;
}