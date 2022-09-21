#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
    int map[22][22], isRoad[22][22];
    int n, ret = 0, isPos = 1;
    scanf("%d", &n);
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d", &map[i][j]);
            isRoad[i][j] = map[i][j];
        }
    }
    
    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
            for(int k=0;k<n;k++) {
                if(i == k || j == k) continue;
                if(map[i][k] + map[k][j] == map[i][j]) {
                    isRoad[i][j] = 0;
                }
                else if(map[i][k] + map[k][j] < map[i][j]) {
                    isPos = 0;
                }
            }
        }
    }
    
    if(!isPos) printf("-1");
    else {
        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                ret += isRoad[i][j];
            }
        }
        printf("%d", ret);
    }
    
    return 0;
}