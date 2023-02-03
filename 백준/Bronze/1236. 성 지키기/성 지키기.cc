#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, M, rowN = 0, colM = 0, isExistR = 0, isExistC = 0;
    char matrix[52][52];
    
    scanf("%d %d", &N, &M);
    
    for(int i=1;i<=N;i++) {
    	getchar();
        for(int j=1;j<=M;j++) {
            scanf("%c", &matrix[i][j]);
        }
    }
    
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            if(j == 1) {
                isExistR = 0;
            }
            if(isExistR == 0 && matrix[i][j] == 'X') {
                isExistR = 1;
                rowN += 1;
            }
        }
    }
    
    for(int i=1;i<=M;i++) {
        for(int j=1;j<=N;j++) {
            if(j == 1) {
                isExistC = 0;
            }
            if(isExistC == 0 && matrix[j][i] == 'X') {
                isExistC = 1;
                colM += 1;
            }
        }
    }
    
    printf("%d", max(N-rowN, M-colM));
    
    return 0;
}