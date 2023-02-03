#include <iostream>
#include <string>
#include <cmath>

using namespace std;


int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    int N, ret1, ret2;
    scanf("%d", &N);
    ret1 = N * 78 / 100;
    ret2 = ((N * 80 / 100)) + ((N * 20 / 100) * 78 / 100);

    printf("%d %d", ret1, ret2);

    return 0;
}