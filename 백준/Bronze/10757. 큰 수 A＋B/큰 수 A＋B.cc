//https://www.acmicpc.net/problem/10757
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void Add(string &s1, string &s2) {
    int a[20001], b[20001], sum[20001], carry=0;

    for(int i=0;i<s1.length();i++) {
        char tmp=s1.at(i);
        a[s1.length()-i]=tmp-'0';
    }
    
    for(int i=0;i<s2.length();i++) {
        char tmp=s2.at(i);
        b[s2.length()-i]=tmp-'0';
    }

    for(int i=1;i<=max(s1.length(),s2.length());i++) {
        sum[i]=a[i]+b[i]+carry;
        if(sum[i] >= 10) {
            sum[i]-=10;
            carry=1;
        }
        else carry=0;
    }

    if(carry) cout << 1;
    for(int i=0;i<max(s1.length(),s2.length());i++) {
        cout << sum[max(s1.length(),s2.length())-i];
    }
    
}

int main() {
    string A, B;
    cin >> A >> B;

    Add(A, B);

    return 0;
}