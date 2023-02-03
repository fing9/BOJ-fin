#include <iostream>
#include <cstdio>
using namespace std;

int solve(int n) {
    int ret=0;
    while(n >= 500) {
        n -= 500;
        ret++;
    }
    while(n >= 100) {
        n -= 100;
        ret++;
    }
    while(n >= 50) {
        n -= 50;
        ret++;
    }
    while(n >= 10) {
        n -= 10;
        ret++;
    }
    while(n >= 5) {
        n -= 5;
        ret++;
    }
    while(n >= 1) {
        n -= 1;
        ret++;
    }
    return ret;
}

int main() {
    int n;
    scanf("%d",&n);
    printf("%d",solve(1000-n));
    return 0;
}