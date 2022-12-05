#include <iostream>
#include <cmath>

using namespace std;

char matrix[1025][1025];

void init();
void draw(int N, int y, int x);
void print(int N);

int main() {
    int N;
    scanf("%d", &N);
    N = pow(2,N);

    init();
    draw(N, 0, 0);
    print(N);

    return 0;
}


void init() {
    for(int i=0;i<1025;i++) {
        for(int j=0;j<1025;j++) {
            matrix[i][j] = ' ';
        }
    }
}

void draw(int N, int y, int x) {
    int dif;
    // base case
    if(N == 0 || N == 1) {
        matrix[y][x] = '*';
        return;
    }

    dif = N/2;
    draw(dif, y, x);
    draw(dif, y + dif, x);
    draw(dif, y, x + dif);

    return;
}

void print(int N) {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N-i;j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}
