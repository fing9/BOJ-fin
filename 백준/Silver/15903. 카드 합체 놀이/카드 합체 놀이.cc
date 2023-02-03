#include <iostream>
#include <queue>

using namespace std;

int main()
{
    unsigned long long n, m, d;
    unsigned long long sum = 0;
    priority_queue<unsigned long long, vector<unsigned long long>, greater<unsigned long long>> v;
    scanf("%llu %llu", &n, &m);

    for (int i = 0; i < n; i++)
    {
        scanf("%llu", &d);
        v.push(d);
    }

    for (int i = 0; i < m; i++)
    {
        unsigned long long tmp = 0;
        tmp += v.top();
        v.pop();
        tmp += v.top();
        v.pop();
        v.push(tmp);
        v.push(tmp);
    }

    for (int i = 0; i < n; i++)
    {
        sum += v.top();
        v.pop();
    }

    printf("%llu", sum);

    return 0;
}