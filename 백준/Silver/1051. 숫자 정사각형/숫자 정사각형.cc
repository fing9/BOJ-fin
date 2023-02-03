#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, M, max = -1, x1=0, y1=0, x2=0, y2=0;
    int matrix[51][51];
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        getchar();
        for(int j = 0; j < M; j++) {
            char c;
            scanf("%c", &c);
            matrix[i][j] = c - '0';
        }
    }

    for(int i1 = 0; i1 < N; i1++) {
        for (int j1 = 0; j1 < M; j1++) {
            for(int i2 = i1; i2 < N; i2++) {
                for(int j2 = j1; j2 < M; j2++) {
                    if(matrix[i1][j1] == matrix[i1][j2] && matrix[i1][j2] == matrix[i2][j2] && matrix[i2][j2] == matrix[i2][j1] && (i2-i1+1) * (j2-j1+1) > max && (i2-i1+1) == (j2-j1+1)) {
                        max = (i2-i1+1) * (j2-j1+1);
                        y1 = i1+1;
                        x1 = j1+1;
                        y2 = i2+1;
                        x2 = j2+1;
                    }
                }
            }
        }
    }

    printf("%d", (y2-y1+1) * (x2-x1+1));

    return 0;
}