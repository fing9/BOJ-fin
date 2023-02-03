#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
    char str[20000000];
    int cur = 1;
    
    while(1) {
        cin.getline(str, 20000000);
        if(!strcmp(str,"0")) {
            return 0;
        }
        printf("Case %d: Sorting... done!\n", cur);
        cur++;
    }
    
    return 0;
}