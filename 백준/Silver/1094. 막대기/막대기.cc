#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// 64=2^6 32=2^5 16=2^4 8=2^3 4=2^2 2=2^1 1=2^0
int main()
{
    int X, ret = 0, sum = 64, sticks[7] = {0,};
    sticks[6] = 1;
    
    scanf("%d", &X);
    
    while(sum>X)
    {
        for(int i=0;i<7;i++)
        {
            if(sticks[i] != 0)
            {
                sticks[i]--;
                if(i!=0) sticks[i-1] += 2;
                if(sum-pow(2,i-1) >= X) sticks[i-1]--;
                break;
            }
        }
        
        sum = 0;
        for(int i=0;i<7;i++)
        {
            for(int j=0;j<sticks[i];j++)
                sum += pow(2,i);
        }
    }
    
    for(int i=0;i<7;i++)
    {
        ret += sticks[i];
    }
    
    printf("%d", ret);
    
    return 0;
}