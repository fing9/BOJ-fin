#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    int X, N, sum = 0;
    scanf("%d", &X);
    scanf("%d", &N);

    for(int i=0;i<N;i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        sum += a * b;
    }
    
    if(X == sum) {
        printf("Yes");
    }
    else {
        printf("No");
    }

    return 0;
}