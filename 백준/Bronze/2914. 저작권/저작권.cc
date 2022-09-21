#include <iostream>

using namespace std;

int main()
{
    int A, I, ret;
    
    scanf("%d %d", &A ,&I);
    
    ret = A * (I - 1) + 1;
    
    printf("%d", ret);
    
    return 0;
}