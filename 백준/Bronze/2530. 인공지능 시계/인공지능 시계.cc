#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    int A, B, C, D;
    scanf("%d %d %d", &A, &B, &C);
    scanf("%d", &D);

    A += D / 3600;
    D %= 3600;
    B += D / 60;
    D %= 60;
    C += D;
    D = 0;

    B += C / 60;
    C %= 60;
    A += B / 60;
    B %= 60;
    A %= 24;

    printf("%d %d %d", A, B, C);

    return 0;
}