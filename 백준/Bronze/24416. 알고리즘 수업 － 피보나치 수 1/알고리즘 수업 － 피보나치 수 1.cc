#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <bitset>
#define INF 987654321

using namespace std;
int f[40] = {0,};

int fib(int n)
{
    if(n == 1 || n == 2) {
        return 1;
    }
    else {
        return (fib(n - 1) + fib(n - 2));
    }
}

int fibonacci(int n)
{
    int cnt = 0;
    f[1] = 1;
    f[2] = 1;
    for(int i=3;i<=n;i++)
    {
        cnt++;
        f[i] = f[i-1] + f[i-2];
    }
    return cnt;
}

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    int n;

    cin >> n;

    cout << fib(n) << " " << fibonacci(n);

    return 0;
}