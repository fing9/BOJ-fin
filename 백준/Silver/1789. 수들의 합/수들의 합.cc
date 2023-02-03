#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

unsigned long long suma(unsigned long long num) {
    if(num%2==0)
        return ((num / 2) * (num+1));
    else
        return (num * ((num+1)/2));
}

unsigned long long solve(unsigned long long S) {
    unsigned long long lo=0, hi=100000;
    while(lo+1<hi) {
        unsigned long long mid=(lo+hi)/2;
        if(suma(mid)>S)
            hi = mid;
        else
            lo = mid;
    }
    return lo;
}

int main() {
    unsigned long long S;
    
    scanf("%llu",&S);
    
    printf("%llu",solve(S));
    
    return 0;
}