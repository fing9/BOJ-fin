#include <iostream>

using namespace std;

int main() {
    char c;
    
    scanf("%c", &c);
    
    if(c == 'n' || c == 'N') printf("Naver D2");
    else printf("Naver Whale");
    
    return 0;
}