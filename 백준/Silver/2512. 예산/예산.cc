#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
vector<long long> v;
long long N, M;

long long sum_all(long long mod) {
    long long ret=0;
    for(int i=0;i<N;i++) {
        if(v[i]>=mod)
            ret += mod;
        else
            ret += v[i];
    }
    return ret;
}

long long binarysearch(long long lo, long long hi) {
    while(lo+1<hi) {
        long long mid=(lo+hi)/2;
        if(sum_all(mid)<=M) {
            lo=mid;
        }
        else {
            hi=mid;
        }
    }
    return lo;
}

int main() {
    long long sum=0, run=1;
    scanf("%lld",&N);
    v.resize(N);
    for(int i=0;i<N;i++) {
        scanf("%lld",&v[i]);
        sum += v[i];
    }
    
    sort(v.begin(),v.end());
    
    scanf("%lld",&M);
    
    if(sum<=M) {
        printf("%lld",v[N-1]);
        return 0;
    }
    
    printf("%lld", binarysearch(0, v[N-1]));
    
    return 0;
}