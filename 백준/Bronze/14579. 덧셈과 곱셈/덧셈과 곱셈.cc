#include <iostream>

using namespace std;

int main() {
    int a, b, ret = 1, sum = 0;

    scanf("%d %d", &a, &b);

    for(int i=1;i<a;i++) sum += i;
    for(int i=a;i<=b;i++) {
        sum += i;
        ret *= (sum % 14579);
        ret %= 14579;
    }

    printf("%d", ret);

    return 0;
}