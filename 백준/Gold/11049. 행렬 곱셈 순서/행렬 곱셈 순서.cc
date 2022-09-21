#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    int N, r, c, DP[502][502];
    vector<pair<int,int> > v;
    
    scanf("%d", &N);
    
    v.push_back(make_pair(0,0));
    for(int i=0;i<N;i++)
    {
        scanf("%d %d", &r, &c);
        v.push_back(make_pair(r,c));
    }
    
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N-i;j++)
        {
            DP[j][j+i] = 1987654321;
            for(int k=j;k<j+i;k++)
            {
                DP[j][j+i] = min(DP[j][j+i], DP[j][k] + DP[k+1][j+i] + v[j].first*v[k].second*v[j+i].second);
            }
        }
    }
    
    printf("%d", DP[1][N]);
    
    return 0;
}