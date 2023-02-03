#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
vector<int> v, ret;

int GCD(int a, int b)
{
    if(a%b == 0)
    {
        return b;
    }

    return GCD(b, a%b);
}

int main()
{
    int N, num, gcd;
    scanf("%d",&N);

    for(int i=0;i<N;i++)
    {
        scanf("%d",&num);
        v.push_back(num);
    }
    sort(v.begin(),v.end()); // 정렬

    gcd=v[1]-v[0];
    for(int i=2;i<N;i++) // v[i]-v[i-1]들의 최대공약수를 찾음
    {
        gcd = GCD(gcd, v[i]-v[i-1]);
    }

    for(int i=2;i*i<=gcd;i++) // v[i]-v[i-1]들의 최대공약수의 약수를 찾음
    {
        if(gcd%i==0)
        {
            ret.push_back(i);
            ret.push_back(gcd/i);
        }
    }
    ret.push_back(gcd);
    sort(ret.begin(),ret.end()); // 정렬

    ret.erase(unique(ret.begin(),ret.end()),ret.end()); // 중복제거
    for(int i=0;i<ret.size();i++)
    {
        printf("%d",ret[i]);
        if(i!=ret.size()-1)
            printf(" ");
    }

    return 0;
}