#include <iostream>
#include <cstdio>
#include <cmath>
#define MOD 10
using namespace std;

int depress(int a, int b) {
    if(b==1) return a % MOD;
    if(b%2==0) return (depress(a, (b/2)) * depress(a, (b/2))) % MOD;
    return (depress(a, (b/2)) * depress(a, (b/2)) * depress(a, 1)) % MOD;
}

int main() {
    int T, a, b, ret;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d", &a, &b);
        ret = depress(a, b);
        if(ret==0)
            printf("10\n");
        else
            printf("%d\n",ret);
    }
    return 0;
}