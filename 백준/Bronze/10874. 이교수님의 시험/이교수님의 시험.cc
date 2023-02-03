#include <iostream>

using namespace std;

int main()
{
    int n;

    scanf("%d", &n);
    
    for(int i=1;i<=n;i++)
    {
        int c, cnt = 0;
        
        for(int j=0;j<10;j++)
        {
            scanf("%d", &c);
            if(c == ((j%5)+1))
                cnt++;
        }
        
        if(cnt == 10)
            printf("%d\n", i);
    }

    return 0;
}