#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, ret = 1987654321;
    scanf("%d", &N);
    
    while(N--) {
        int s, e;
        scanf("%d %d", &s, &e);
        if(s <= e) {
            ret = min(ret, e);
        }
    }
    
    if(ret == 1987654321) printf("-1");
    else printf("%d", ret);
    
    return 0;
}