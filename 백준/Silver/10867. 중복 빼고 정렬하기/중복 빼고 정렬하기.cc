#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v;
    int N, inp, last;
    
    scanf("%d", &N);
    
    for(int i=0;i<N;i++)
    {
        scanf("%d",&inp);
        v.push_back(inp);
    }
    
    sort(v.begin(),v.end());
    
    last = v[0];
    printf("%d", v[0]);
    for(int i=1;i<N;i++)
    {
        if(v[i]!=last) printf(" %d", v[i]);
        last = v[i];
    }
    
    return 0;
}