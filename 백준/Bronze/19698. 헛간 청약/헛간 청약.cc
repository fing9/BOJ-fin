#include <iostream>
using namespace std;

int main()
{
    int N, W, H, L;
    scanf("%d %d %d %d", &N, &W, &H, &L);
    
    printf("%d", min((W/L)*(H/L), N));
    
    return 0;
}