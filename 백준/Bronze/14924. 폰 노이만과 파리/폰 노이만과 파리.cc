#include <iostream>

using namespace std;

int main() {
    int S, T, D;
    
    scanf("%d %d %d", &S, &T, &D);
    
    printf("%d", D/(S*2) * T);
    
    return 0;
}