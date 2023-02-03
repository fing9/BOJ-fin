#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <bitset>

using namespace std;

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    int T;
    int A = 0, B = 0, C = 0;
    cin >> T;
    while(T>0) {
        if(T >= 300) {
            A++;
            T -= 300;
        }
        else if(T >= 60) {
            B++;
            T -= 60;
        }
        else {
            C++;
            T -= 10;
        }
    }

    if(T == 0)
        cout << A << " " << B << " " << C;
    else
        cout << "-1";



    return 0;
}