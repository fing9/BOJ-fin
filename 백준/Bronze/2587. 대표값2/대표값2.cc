#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    int inp, avr = 0;
    
    for(int i=0;i<5;i++) {
        scanf("%d", &inp);
        v.push_back(inp);
        avr += inp;
    }
    
    sort(v.begin(),v.end());
    
    printf("%d\n%d", avr/5, v[2]);
    
    return 0;
}