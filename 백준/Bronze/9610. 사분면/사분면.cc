#include <iostream>

using namespace std;


int main() {
    int s1 = 0, s2 = 0, s3 = 0, s4 = 0, as = 0;
    int n;
    
    scanf("%d", &n);
    
    for(int i=0;i<n;i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if(x > 0 && y > 0) {
            s1++;
        }
        else if(x < 0 && y > 0) {
            s2++;
        }
        else if(x < 0 && y < 0) {
            s3++;
        }
        else if(x > 0 && y < 0){
            s4++;
        }
        else {
            as++;
        }
    }
    
    printf("Q1: %d\nQ2: %d\nQ3: %d\nQ4: %d\nAXIS: %d", s1, s2, s3, s4, as);
    
    return 0;
}