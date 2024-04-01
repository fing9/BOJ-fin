#include <iostream>

using namespace std;

int main()
{
    int yAns = 2147483647, xAns = -1, N;
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        
        if (y < yAns) {
            xAns = x;
            yAns = y;
        }
    }
    printf("%d %d\n", xAns, yAns);
}