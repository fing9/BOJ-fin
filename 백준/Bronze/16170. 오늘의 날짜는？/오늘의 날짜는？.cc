#include <iostream>
#include <string>
#include <cmath>
#include <time.h>

using namespace std;

long long newOper(long long a, long long b)
{
    return (a+b) * (a-b);
}

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    time_t t = time(NULL);
    struct tm tm = *gmtime(&t);
    printf("%d\n%d\n%d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

    return 0;
}