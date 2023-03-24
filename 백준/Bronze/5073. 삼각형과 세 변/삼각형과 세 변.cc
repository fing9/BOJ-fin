#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <string.h>

#define INF 987654321
#define ll long long

using namespace std;

int main() {
    int a, b, c;

    do{
        scanf("%d %d %d", &a, &b, &c);
        if ((a == 0) && (b == 0) && (c == 0))
            break ;
        if ((a + b <= c) || (a + c <= b) || (b + c <= a))
            printf("Invalid\n");
        else if ((a == b) && (b == c))
            printf("Equilateral\n");
        else if ((a == b) || (b == c) || (a == c))
            printf("Isosceles\n");
        else
            printf("Scalene\n");
    }while (1);

    return (0);
}