#include <iostream>
#include <string>
using namespace std;

int main() {
    string str, hj = ":", fan = ":fan:";
    
    cin >> str;
    
    hj += str + ":";
    
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if(i == 1 && j == 1) cout << hj;
            else cout << fan;
        }
        cout << "\n";
    }
    
    return 0;
}