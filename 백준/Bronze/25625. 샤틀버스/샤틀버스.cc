#include <iostream>

using namespace std;

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    
    if (x > y)
        printf("%d", x+y);
    else
        printf("%d", y%x);
    return 0;
}