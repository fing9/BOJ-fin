#include <iostream>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    
    while(T--) {
        int c;
        scanf("%d", &c);
        printf("%d ", c/25);
        c %= 25;
        printf("%d ", c/10);
        c %= 10;
        printf("%d ", c/5);
        c %= 5;
        printf("%d\n", c);
    } 
    
    return 0;
}