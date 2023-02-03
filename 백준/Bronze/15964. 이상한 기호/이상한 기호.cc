#include <iostream>
#include <string>
#include <cmath>

using namespace std;

long long newOper(long long a, long long b)
{
    return (a+b) * (a-b);
}

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    long long a, b;
    scanf("%lld %lld", &a, &b);
    printf("%lld", newOper(a, b));

    return 0;
}