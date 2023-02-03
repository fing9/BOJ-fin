#include <iostream>
#include <string>
#include <cmath>

using namespace std;


int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    int ax, ay, az;
    int bx, by, bz;
    int cx, cy, cz;

    scanf("%d %d %d", &ax, &ay, &az);
    scanf("%d %d %d", &cx, &cy, &cz);

    bx = cx - az;
    by = cy / ay;
    bz = cz - ax;

    printf("%d %d %d", bx, by, bz);

    return 0;
}