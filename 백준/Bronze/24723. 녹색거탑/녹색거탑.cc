#include <iostream>

using namespace std;

int main()
{
    int N, ans=1;
    
    scanf("%d", &N);
    
    for(int i=0;i<N;i++)
    {
        ans *= 2;
    }
    
    printf("%d", ans);
    
    return 0;
}