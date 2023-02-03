#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
int n, m;
int matrix[28][28];

void init() {
    for(int i=0;i<28;i++) {
        for(int j=0;j<28;j++) {
            matrix[i][j] = 0;
        }
    }
}

int main() {
    
    init();
    
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        char a, b;
        getchar();
        scanf("%c is %c", &a, &b);
        a -= 'a' - 1;
        b -= 'a' - 1;
        matrix[a][b] = 1;
    }
    
    for(int l=1;l<=26;l++) {
        for(int i=1;i<=26;i++) {
            for(int j=1;j<=26;j++) {
                for(int k=1;k<=26;k++) {
                    if(i==k || j==k) continue;
                    
                    if(matrix[i][k] == 1 && matrix[k][j] == 1) {
                        matrix[i][j] = 1;
                    }
                }
            }
        }
    }
    
    scanf("%d", &m);
    for(int i=0;i<m;i++) {
        char a, b;
        getchar();
        scanf("%c is %c", &a, &b);
        a -= 'a' - 1;
        b -= 'a' - 1;
        
        if(matrix[a][b] == 1) printf("T\n");
        else printf("F\n");
    }
    
    return 0;
}