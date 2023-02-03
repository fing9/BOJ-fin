#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    int N, K;
    int data[1002][5];
    vector<pair<int, int> > v;
    scanf("%d %d",&N,&K);
    
    for(int i=0;i<1002;i++)
    {
        data[i][4]=0;
    }
    
    for(int i=1;i<=N;i++)
    {
        scanf("%d %d %d %d",&data[i][0],&data[i][1],&data[i][2],&data[i][3]);
    }
    
    for(int i=1;i<=N;i++)
    {
        for(int j=i+1;j<=N;j++)
        {
            if(data[i][1] > data[j][1])
            {
                data[j][4]++;
                continue;
            }
            else if(data[i][1] == data[j][1])
            {
                if(data[i][2] > data[j][2])
                {
                    data[j][4]++;
                    continue;
                }
                else if(data[i][2] == data[j][2])
                {
                    if(data[i][3] > data[j][3])
                    {
                        data[j][4]++;
                        continue;
                    }
                    else if(data[i][3] == data[j][3])
                    {
                        continue;
                    }
                }
            }
            data[i][4]++;
        }
    }
    
    for(int i=1;i<=N;i++)
    {
        v.push_back(pair<int, int>(data[i][4], data[i][0])); // 자기보다 강한 나라의 숫자, 자기나라의 번호
    }
    sort(v.begin(), v.end());
    
    for(int i=0;i<N;i++)
    {
        if(v[i].second==K)
        {
            printf("%d",v[i].first+1);
            break;
        }
    }
    
    return 0;
}