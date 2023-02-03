#include <iostream>

using namespace std;

int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    
    cnt = n / 5;
    n %= 5;
    
    while(n > 0) {
        if(n % 2 == 0) {
            cnt += n / 2;
            n -= (n / 2) * 2;
        }
        else if(cnt > 0){
            cnt -= 1;
            n += 5;
        }
        else {
            n = -1;
        }
    }
    
    if(n == 0)
        printf("%d", cnt);
    else
        printf("-1");
    
    return 0;
}