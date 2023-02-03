#include <iostream>
#include <vector>
using namespace std;
const long long int mod = 1000000007;

vector<vector<long long> > multiple(vector<vector<long long> >& a, vector<vector<long long> >& b)
{
    vector<vector<long long> > c(2, vector<long long>(2)); //2by2 matrix
    
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= mod;
        }
    }
    return c;
}

int main()
{
    long long int n;
    
    // 1 1
    // 1 0
    vector<vector<long long> > ans = {{1,0}, {0,1}}; //start
    vector<vector<long long> > a = {{1,1}, {1,0}};
    
    scanf("%lld", &n);
    
    while(n>0)
    {
        if(n%2 == 1)
        {
            ans = multiple(ans, a);
        }
        a = multiple(a, a);
        n /= 2;
    }
    
    printf("%lld", ans[0][1]);
    
    return 0;
}