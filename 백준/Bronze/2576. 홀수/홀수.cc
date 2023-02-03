#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int d, sum = 0, minN;
    
    for(int i=0;i<7;i++) {
        scanf("%d", &d);
        if(d % 2 == 1) {
            sum += d;
            if(i == 0)
                minN = d;
            else
                minN = min(minN, d);
        }
    }
    
    if(sum != 0)
        printf("%d\n%d", sum, minN);
    else
        printf("-1");
    
    return 0;
}