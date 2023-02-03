#include <iostream>

using namespace std;

int main()
{
    
    while(1) {
        int d, sum = 2, cnt = 0;
        scanf("%d", &d);
        if(d == 0) {
            return 0;
        }
        else {
            while(d>0) {
                if(d % 10 == 0)
                    sum += 4;
                else if(d % 10 == 1)
                    sum += 2;
                else
                    sum += 3;
                cnt++;
                sum += 1;
                d /= 10;
            }
            sum -= 1;
        }
        printf("%d\n", sum);
    }
    
    return 0;
}