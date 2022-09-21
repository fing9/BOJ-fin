#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    int A, B;
    scanf("%d %d", &A, &B);
    A = B - A;
    printf("%d %d", A, B);

    return 0;
}