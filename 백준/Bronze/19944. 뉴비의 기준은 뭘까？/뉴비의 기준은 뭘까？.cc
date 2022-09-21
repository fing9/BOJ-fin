#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    if(M <= 2) { // newbie
        cout << "NEWBIE!";
    }
    else if(M <= N && M > 2) { // oldbie
        cout << "OLDBIE!";
    }
    else { // TLE
        cout << "TLE!";
    }
    
    return 0;
}