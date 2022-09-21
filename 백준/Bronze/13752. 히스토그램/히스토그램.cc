#include <iostream>

using namespace std;

int main() {
    int n, arr[101];
    cin >> n;
    
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        for(int j=0;j<arr[i];j++) {
            cout << '=';
        }
        cout << '\n';
    }
    
    return 0;
}