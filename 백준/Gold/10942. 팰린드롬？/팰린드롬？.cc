#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int N, M, S, E;
bool DP[2002][2002] ={false, };
int arr[2002] = {0,};
vector<pair<int,int> > v;

int main()
{
    scanf("%d", &N);
    
    for(int i=1;i<=N;i++)
    {
        scanf("%d", &arr[i]);
    }
    
    scanf("%d", &M);
    
    for(int i=1;i<=M;i++)
    {
        scanf("%d %d", &S, &E);
        v.push_back(make_pair(S,E));
    }
    
	for(int i=1;i<=N;i++) 
        DP[i][i] = true;
    
	for(int i=1;i<N;i++) 
    {
		if(arr[i] == arr[i+1])
			DP[i][i+1] = true;
	}
    
	for (int i=N-1;i>=1;i--)
	{
		for (int j=i+2;j<=N;j++)
		{
            if(DP[i+1][j-1] && arr[i]==arr[j]) DP[i][j] = true;
        }
    }
    
    for(int i=0;i<M;i++)
    {
        if(DP[v[i].first][v[i].second]) printf("1\n");
        else printf("0\n");
    }
    
    return 0;
}