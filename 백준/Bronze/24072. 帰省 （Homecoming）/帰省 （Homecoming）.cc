#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    int A, B, C;

    scanf("%d %d %d", &A, &B, &C);
    if (A <= C && C < B)
        printf("1");
    else
        printf("0");

    return 0;
}