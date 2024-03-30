#include <iostream>

using namespace std;

int main() {
    int N, F;
    
    scanf("%d\n%d", &N, &F);
    if (1 <= F - N && F - N <= 20) {
        printf("You are speeding and your fine is $100.");
    } else if (21 <= F - N && F - N <= 30) {
        printf("You are speeding and your fine is $270.");
    } else if (31 <= F - N) {
        printf("You are speeding and your fine is $500.");
    } else {
        printf("Congratulations, you are within the speed limit!");
    }
    
    return 0;
}