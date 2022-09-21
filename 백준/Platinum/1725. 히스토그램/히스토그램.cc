#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

long long solve(vector<long long>& h, long long left, long long right){
    //기저 사례: 판자가 하나밖에 없는 경우
    if(left == right) return h[left];
    //[left, mid], [mid+1, right]의 두 구간으로 문제를 분할한다.
    long long mid = (left + right) / 2;
    //분할한 문제를 각개격파
    long long ret = max(solve(h, left, mid), solve(h, mid+1, right));
    //부분 문제3: 두 부분에 모두 걸치는 사각형 중 가장 큰 것을 찾는다.
    long long lo = mid, hi = mid+1;
    long long height = min(h[lo], h[hi]);
    //[mid, mid+1]만 포함하는 너비 2인 사각형을 고려한다.
    ret = max(ret, height * 2);
    //사각형이 입력 전체를 덮을 때 까지 확장해 나간다.
    while(left < lo || hi < right){
        //항상 높이가 더 높은 쪽으로 확장한다.
        if(hi < right && (lo == left || h[lo-1] < h[hi+1])) {
            ++hi;
            height = min(height, h[hi]);
        }
        else {
            --lo;
            height = min(height, h[lo]);
        }
        //확장한 후 사각형의 넓이
        ret = max(ret, height * (hi - lo + 1));
    }
    return ret;
}

int main(){
    long long n;
    long long num;
    vector<long long> h;
    
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&num);
        h.push_back(num);
    }
    printf("%lld",solve(h, 0, n-1));
    
    return 0;
}