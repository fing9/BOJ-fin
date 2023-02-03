#include <iostream>

using namespace std;

int ans[8] = {4, 3, 2, 1, 2, 3, 4, 5};

int main()
{
    int n;
    
    scanf("%d", &n);
    
    if(n<=5)
    {
        printf("%d", n);
        return 0;
    }
    
    n -= 6;
    printf("%d", ans[n % 8]);
    
    return 0;
}