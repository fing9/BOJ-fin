#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define ll long long
#define MACK 18
#define ZACK 17

using namespace std;

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d", a + b + c - min(a, min(b, c)));
}
