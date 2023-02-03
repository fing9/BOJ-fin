#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
vector<int> v;

bool binary_search(int lo, int hi, int target) {
    int mid = (lo + hi) / 2;
    
    if(v[lo] == target || v[hi] == target)
        return true;
    if(lo == hi)
        return false;
    
    if(v[lo] <= target  && target <= v[mid])
        return binary_search(lo, mid, target);
    else if(v[mid+1] <= target  && target <= v[hi])
        return binary_search(mid+1, hi, target);
    else
        return false;
}

int main() {
    int N, M, num;
    scanf("%d",&N);
    for(int i=0;i<N;i++) {
        scanf("%d",&num);
        v.push_back(num);
    }
    sort(v.begin(),v.end()); // v 벡터 정렬
    scanf("%d",&M);
    for(int i=0;i<M;i++) {
        scanf("%d",&num);
        if(binary_search(0, N-1, num))
            printf("1 ");
        else
            printf("0 ");
    }
    return 0;
}