#include <iostream>

using namespace std;

int main() {
    int R, C, N;
    long long retR, retC;
    scanf("%d %d %d",  &R, &C, &N);
    
    retR = R % N == 0 ? (R / N) : ((R / N) + 1);
    retC = C % N == 0 ? (C / N) : ((C / N) + 1);
    printf("%lld", retR * retC);
    
    return 0;
}