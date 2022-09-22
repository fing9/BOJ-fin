#include <stdio.h>

int main(){
    int T;
    scanf("%d", &T);

    while(T--) {
        int a, b, ret = 0;
        scanf("%d %d", &a, &b);
        if(a != 0) {
            if(a <= 1) ret += 500;
            else if(a <= 3) ret += 300;
            else if(a <= 6) ret += 200;
            else if(a <= 10) ret += 50;
            else if(a <= 15) ret += 30;
            else if(a <= 21) ret += 10;
        }

        if(b != 0) {
            if(b <= 1) ret += 512;
            else if(b <= 3) ret += 256;
            else if(b <= 7) ret += 128;
            else if(b <= 15) ret += 64;
            else if(b <= 31) ret += 32;
        }

        ret *= 10000;

        printf("%d\n", ret);
    }


    return 0;
}