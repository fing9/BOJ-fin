#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
vector<long long> A, B, C, D, E;
long long ret=0;

void BinarySearch(long long target) {
    long long lo=0, hi=E.size();
    long long lower=-1, upper=-1;
    int run1=0, run2=0;
    
    while(lo<hi) {
        long long mid=(lo+hi)/2;
        if(E[mid] < target) {
            lo = mid+1;
        }
        else {
            if(E[mid] == target)
                run1 = 1;
            hi = mid;
        }
    }
    lower=hi;
    
    lo=0;
    hi=E.size();
    
    while(lo<hi) {
        long long mid=(lo+hi)/2;
        if(E[mid] <= target) {
            if(E[mid] == target)
                run2 = 1;
            lo = mid+1;
        }
        else {
            hi = mid;
        }
    }
    upper=hi;
    
    ret += upper - lower;
    
    return;
}

int main() {
    long long N;
    scanf("%lld",&N);
    A.resize(N);
    B.resize(N);
    C.resize(N);
    D.resize(N);
    
    for(int i=0;i<N;i++) {
        scanf("%lld %lld %lld %lld",&A[i],&B[i],&C[i],&D[i]);
    }
    
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            E.push_back(-(A[i]+B[j]));
        }
    }
    sort(C.begin(),C.end());
    sort(D.begin(),D.end());
    sort(E.begin(),E.end());
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            BinarySearch(C[i]+D[j]);
        }
    }
    
    printf("%lld", ret);
    
    return 0;
}