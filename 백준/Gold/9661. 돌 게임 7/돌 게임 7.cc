#include <iostream>

using namespace std; 

int main() { 
    long long int n; 
    scanf("%lld", &n);
    
    n = n % 5; 
    
    if (n == 0 || n == 2) printf("CY"); 
    else printf("SK");
    
    return 0;
}
