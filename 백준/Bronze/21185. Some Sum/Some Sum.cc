#include <iostream>

using namespace std;

int main() {
    int N, odd = 0, even = 0;
    
    scanf("%d", &N);
    
    for(int i=1;i<=100 - N;i++) {
        int sum = 0;
        for(int j=i;j<i+N;j++) {
            sum += j;
        }
        
        if(sum % 2 == 0) even++;
        else odd++;
    }
    
    if(even == 0) printf("Odd");
    else if(odd == 0) printf("Even");
    else printf("Either");
    
    return 0;
}