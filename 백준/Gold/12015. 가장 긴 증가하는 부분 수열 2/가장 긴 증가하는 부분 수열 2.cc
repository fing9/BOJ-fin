#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
int N, arr[1000001];
vector<int> v;

int solve(int target) {
    int lo=0, hi=v.size()-1;
    while(lo<hi) {
        int mid=(lo+hi) / 2;
        if(v[mid] >= target)
            hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main() {
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d",&arr[i]);
    for(int i=0;i<N;i++) {
        if(v.size() == 0)
            v.push_back(arr[i]);
        else if(v.back() < arr[i])
            v.push_back(arr[i]);
        else
            v[solve(arr[i])] = arr[i];
    }
    
    printf("%d",v.size());
    
    return 0;
}