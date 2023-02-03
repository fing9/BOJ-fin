#include <iostream>
using namespace std;

int main()
{
    int N, Y = 0, M = 0;
    scanf("%d", &N);
    while(N--)
    {
        int d;
        scanf("%d", &d);
        Y += ((d / 30) + 1) * 10;
        M += ((d / 60) + 1) * 15;
    }
    
    if(Y < M)
        printf("Y %d", Y);
    else if(Y > M)
        printf("M %d", M);
    else
        printf("Y M %d", Y);
    
    return 0;
}