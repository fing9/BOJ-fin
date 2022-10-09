#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    printf("%d", min(N/2, M/2));
    
    return 0;
}