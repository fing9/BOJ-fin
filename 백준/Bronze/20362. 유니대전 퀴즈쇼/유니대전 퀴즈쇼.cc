#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
string str[1001][2];

int main() {
    int N, ret=0;
    string S, answer;
    
    cin >> N >> S;
    for(int i=0;i<N;i++) {
        cin >> str[i][0] >> str[i][1];
        if(str[i][0].compare(S)==0) {
            answer = str[i][1];
        }
    }
    
    for(int i=0;i<N;i++) {
        if(str[i][0].compare(S)==0) {
            break;
        }
        else if(str[i][1].compare(answer)==0) {
            ret++;
        }
    }
    
    cout << ret;
    
    return 0;
}