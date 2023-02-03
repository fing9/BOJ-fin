#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> v;
    int N, check[51] = {0,};
    cin >> N;
    
    for(int i=0;i<N;i++) {
        string str;
        cin >> str;
        v.push_back(str);
    }
    
    for(int i=1;i<N;i++) {
        for(int j=0;j<v[0].size();j++) {
            if(check[j] == 1) continue;
            if(v[i][j] != v[0][j]) {
                check[j] = 1;
            }
        }
    }
    
    for(int i=0;i<v[0].size();i++) {
        if(check[i] == 0) {
            cout << v[0][i];
        }
        else {
            cout << '?';
        }
    }
    
    return 0;
}