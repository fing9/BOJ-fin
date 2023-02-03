#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
long long two_ret=0, five_ret=0;

void get_zero_plus(long long N)
{
    long long two=2, five=5;
    while(two<=N)
    {
        two_ret += N/two;
        two*=2;
    }
    while(five<=N)
    {
        five_ret += N/five;
        five *= 5;
    }
    return;
}

void get_zero_minus(long long N)
{
    long long two=2, five=5;
    while(two<=N)
    {
        two_ret -= N/two;
        two*=2;
    }
    while(five<=N)
    {
        five_ret -= N/five;
        five *= 5;
    }
    return;
}

int main()
{
    long long  n, m;
    scanf("%lld %lld",&n,&m);

    get_zero_plus(n);
    get_zero_minus(n-m);
    get_zero_minus(m);

    printf("%lld",min(two_ret, five_ret));

    return 0;
}