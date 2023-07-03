#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>

using namespace std;

// 왼쪽 : 1
// 위쪽 : 16
// 오른쪽 : 256
// 아래쪽 : 3840

int main() {
    for (int i=0;i<30;i++) {
        for (int j=0;j<30;j++) {
            if(i==15 && j<15) printf("1 ");
            else if(j==15 && i<15) printf("16 ");
            else if(i==15 && j>15) printf("256 ");
            else if(j==15 && i>15) printf("3840 ");
            else printf("0 ");
        }
        printf("\n");
    }
    return (0);
} 