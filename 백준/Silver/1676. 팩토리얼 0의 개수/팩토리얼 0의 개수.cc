#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int N, num=0, num_2=0, num_5=0;
    scanf("%d",&N);
    
    for(int i=1;i<=N;i++)
    {
        num=i;
        while(num%2==0 || num%5==0)
        {
            if(num%2==0)
            {
                num/=2;
                num_2++;
            }
            else if(num%5==0)
            {
                num/=5;
                num_5++;
            }
        }
    }
    
    if(num_2<=num_5)
        printf("%d",num_2);
    else
        printf("%d",num_5);
    
    return 0;
}