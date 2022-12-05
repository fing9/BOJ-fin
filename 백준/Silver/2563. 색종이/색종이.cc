#include <iostream>
#include <cmath>

using namespace std;

char matrix[101][101];

void init() {
    for(int i=0;i<101;i++) {
        for(int j=0;j<101;j++) {
            matrix[i][j] = ' ';
        }
    }
}

void draw(int y, int x) {
    for(int i=y;i<y+10;i++) {
        for(int j=x;j<x+10;j++) {
            matrix[i][j] = '*';
        }
    }
}

void print() {
    int cnt = 0;
    for(int i=0;i<101;i++) {
        for(int j=0;j<101;j++) {
            if(matrix[i][j] == '*') cnt++;
        }
    }
    
    printf("%d", cnt);
    
    return;
}

int main() {
    int N, y, x;
    scanf("%d", &N);

    init();
    for(int i=0;i<N;i++) {
        scanf("%d %d", &y, &x);
        draw(y, x);
    }
    print();

    return 0;
}
