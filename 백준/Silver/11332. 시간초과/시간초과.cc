#include <iostream>
#include <cstring>
#include <cmath>
#define SEC 100000000
using namespace std;

long long factorial(int N) {
    if(N <= 1) return 1;

    return N * factorial(N-1);
}

int main() {
    int C;
    long long N, T, L;
    char str[8];
    scanf("%d", &C);
    for(int i=0;i<C;i++) {
        double ret;
        scanf("%s %lld %lld %lld", str, &N, &T, &L);
        if(strcmp(str, "O(N)") == 0) {
            ret = T * ((double)N / SEC);
            if(ret > L) printf("TLE!\n");
            else printf("May Pass.\n");
        }
        else if(strcmp(str, "O(N^2)") == 0) {
            ret = T * N * ((double)N / SEC);
            if(ret > L || N > 35000) printf("TLE!\n");
            else printf("May Pass.\n");
        }
        else if(strcmp(str, "O(N^3)") == 0) {
            ret = T * N * N * ((double)N / SEC);
            if(ret > L || N > 1000) printf("TLE!\n");
            else printf("May Pass.\n");
        }
        else if(strcmp(str, "O(2^N)") == 0) {
            ret = T * ((double)pow(2, N) / SEC);
            if(ret > L || N >= 30) printf("TLE!\n");
            else printf("May Pass.\n");
        }
        else if(strcmp(str, "O(N!)") == 0) {
            ret = (double)T * factorial(N) / SEC;
            if(ret > L || N > 12) printf("TLE!\n");
            else printf("May Pass.\n");
        }
    }

    return 0;
}