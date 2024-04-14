#include <iostream>

using namespace std;

int main() {
    int X;
    
    scanf("%d", &X);
    if (X % 7 == 2) {
        printf("1");
    } else {
        printf("0");
    }
}