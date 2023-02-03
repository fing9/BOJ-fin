#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[101];
    int n, v, cnt = 0;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    cin >> v;
    for(int i=0;i<n;i++) {
        if(arr[i] == v)
            cnt++;
    }
    cout << cnt;

    return 0;
}