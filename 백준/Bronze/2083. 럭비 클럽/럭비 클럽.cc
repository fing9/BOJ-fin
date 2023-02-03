#include <iostream>
#include <string>
using namespace std;

int main() {
    
    while(1) {
        string str;
        int y, kg;
        cin >> str >> y >> kg;
        if(str == "#" && y == 0 && kg == 0) break;
        if(y>17 || 80<=kg) cout << str << " " << "Senior\n";
        else cout << str << " " << "Junior\n";
    }
    
    return 0;
}