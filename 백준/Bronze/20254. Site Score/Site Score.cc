#include <iostream>

using namespace std;

int main() {
    int Ur, Tr, Uo, To, ret;
    
    scanf("%d %d %d %d", &Ur, &Tr, &Uo, &To);
    
    ret = (56 * Ur) + (24 * Tr) + (14 * Uo) + (6 * To);
    
    printf("%d", ret);
    
    return 0;
}