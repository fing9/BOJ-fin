#include<iostream>

using namespace std;

int main()
{
    int sum, d;
    
    scanf("%d" ,&sum);
    
    for(int i=0;i<9;i++)
    {
        scanf("%d",&d);
        sum -= d;
    }
    
    printf("%d", sum);
    
    return 0;
}