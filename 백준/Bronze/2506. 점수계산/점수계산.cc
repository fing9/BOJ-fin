#include <iostream>

using namespace std;

int main()
{
    int N, last = 0, now = 0, ret = 0;
    
    scanf("%d", &N);
    
    for(int i=1;i<=N;i++) {
        int d;
        
        scanf("%d", &d);
        
        if(d == 1) {
            if(last == i - 1)
                now++;
            ret += now;
            last = i;
        }
        else {
            now = 1;
        }
    }
    
    printf("%d", ret);
    
    return 0;
}