#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <string.h>

#define INF 987654321

using namespace std;

int main() {
    int T, S;

    scanf("%d %d", &T, &S);
    if ((12 <= T && T <= 16) && (S == 0))
        printf("320");
    else
        printf("280");

    return (0);
}