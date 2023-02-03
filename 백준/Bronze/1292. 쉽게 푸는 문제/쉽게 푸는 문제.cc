#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a, b, sum = 0;
    vector<int> v;
    scanf("%d %d", &a, &b);
    
    for(int i=1;i<=1000;i++)
    {
        for(int j=1;j<=i;j++)
        {
            v.push_back(i);
        }
    }
    
    for(int i=a-1;i<=b-1;i++)
    {
        sum += v[i];
    }
    
    printf("%d", sum);
    
    return 0;
}