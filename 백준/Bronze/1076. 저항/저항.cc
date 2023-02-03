#include<iostream>
#include<string>

using namespace std;

int judge(string str) {
    if(str == "black") return 0;
    else if(str == "brown") return 1;
    else if(str == "red") return 2;
    else if(str == "orange") return 3;
    else if(str == "yellow") return 4;
    else if(str == "green") return 5;
    else if(str == "blue") return 6;
    else if(str == "violet") return 7;
    else if(str == "grey") return 8;
    else if(str == "white") return 9;
}

int main() {
    string str[3];
    long long ret = 0;
    for(int i=0;i<3;i++) {
        cin >> str[i];
    }
    
    for(int i=0;i<2;i++) {
        int d = judge(str[i]);
        
        if(d != 0) {
            ret += d;
            if(i != 1)
                ret *= 10;
        }
    }
    
    for(int i=0;i<judge(str[2]);i++) {
        ret *= 10;
    }
    cout << ret;
    
    return 0;
}