#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    double a, b;
    scanf("%lf %lf", &a, &b);

    if(100.0 <= a - (a * (b / 100))) {
        printf("0");
    }
    else {
        printf("1");
    }


    return 0;
}