#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<long long> v, v2;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        long long arg;
        scanf("%lld",&arg);
        v.push_back(arg);
        v2.push_back(arg);
    }
    
    sort(v2.begin(), v2.end());
    v2.erase(unique(v2.begin(),v2.end()),v2.end());
    
    for(int i=0; i<v.size(); i++)
    {
        printf("%lld ", lower_bound(v2.begin(), v2.end(), v[i]) - v2.begin());
    }
    
    return 0;
}