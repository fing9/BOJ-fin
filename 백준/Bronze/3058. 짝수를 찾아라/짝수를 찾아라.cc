#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    
    while(t--)
    {
        int minN = 987654321, sum = 0;
        for(int i=0;i<7;i++) {
            int d;
            scanf("%d", &d);
            if(d % 2 == 0)
            {
                sum += d;
                minN = min(minN,d);
            }
        }
        printf("%d %d\n", sum, minN);
    }
    
    return 0;
}