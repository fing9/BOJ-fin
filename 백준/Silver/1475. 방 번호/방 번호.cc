#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int numarr[10]={0,};

int main()
{
    int N, num, answer=0;
    scanf("%d",&N);
    
    while(N>0)
    {
        num=N%10;
        N/=10;
        numarr[num]++;
    }
    
    numarr[6]+=numarr[9];
    if(numarr[6]%2==0)
        numarr[6]/=2;
    else
    {
        numarr[6]/=2;
        numarr[6]++;
    }
    numarr[9]=0;
    
    for(int i=0;i<10;i++)
    {
        answer = max(answer,numarr[i]);
    }
    
    printf("%d",answer);
    
    return 0;
}