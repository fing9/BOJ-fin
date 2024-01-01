#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long

using namespace std;

int main() {
    int t;
    int map[10][21];
    char h;
    int w;

    for (int i=0;i<10;i++) {
        for (int j=0;j<21;j++) {
            map[i][j] = 0;
        }
    }
    scanf("%d%*c", &t);
    while (t--) {
        scanf("%c%d%*c", &h, &w);
        map[h-'A'][w-1] = 1;
    }
    for (int i=0;i<10;i++) {
        for (int j=0;j<20;j++) {
            if (map[i][j] == 1)
                printf("o");
            else
                printf(".");
        }
        printf("\n");
    }
    return 0;
}
