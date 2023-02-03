#include <iostream>

using namespace std;

int map[101][101];

void init() {
    for(int i=0;i<101;i++) {
        for(int j=0;j<101;j++) {
            map[i][j] = 0;
        }
    }
}

void addPaper(int x1, int y1, int x2, int y2) {
    for(int i=x1;i<=x2;i++) {
        for(int j=y1;j<=y2;j++) {
            map[i][j]++;
        }
    }
}

int solve(int M) {
    int ret = 0;
    
    for(int i=1;i<101;i++) {
        for(int j=1;j<101;j++) {
            if(map[i][j] > M) {
                ret++;
            }
        }
    }
    
    return ret;
}

int main()
{
    int N, M, ans;
    int x1, y1, x2, y2;
    scanf("%d %d", &N, &M);
    
    init();
    
    for(int i=0;i<N;i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        addPaper(x1, y1, x2, y2);
    }

    ans = solve(M);
    
    printf("%d", ans);
    
    return 0;
}