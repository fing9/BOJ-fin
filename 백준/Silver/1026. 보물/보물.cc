#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

int main()
{
    int N, num, ret=0;
    vector<int> a, b;
    
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&num);
        a.push_back(num);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<N;i++)
    {
        scanf("%d",&num);
        b.push_back(num);
    }
    sort(b.begin(),b.end(),greater<int>());
    
    for(int i=0;i<N;i++)
    {
        ret+=a[i]*b[i];
    }
    printf("%d",ret);
    
    return 0;
}
