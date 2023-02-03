#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int T;
    
    scanf("%d", &T);
    
    while(T--) {
        int score[5], minN = 11, maxN = 0, total = 0, minM = 11, maxM = 0;
        int idxMax, idxMin;
        for(int i=0;i<5;i++) {
            scanf("%d", &score[i]);
            if(maxN <= score[i]){
                maxN = max(maxN, score[i]);
                idxMax = i;
            }
            if(minN >= score[i]){
                minN = min(minN, score[i]);
                idxMin = i;
            }
            total += score[i];
        }
        total -= maxN + minN;
        
        for(int i=0;i<5;i++) {
            if(i != idxMax && i != idxMin) {
                maxM = max(maxM, score[i]);
                minM = min(minM, score[i]);
            }
        }
        
        if(maxM - minM >= 4) {
            printf("KIN\n");
        }
        else {
            printf("%d\n", total);
        }
    }
    
    return 0;
}