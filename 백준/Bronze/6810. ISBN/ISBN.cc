#include <iostream>

using namespace std;

int main() {
    int ret = 91;
    int a, b, c;
    scanf("%d\n%d\n%d", &a, &b, &c);
    
    ret += (1*a) + (3*b) + (1*c);
    
    printf("The 1-3-sum is %d", ret);
    
    return 0;
}