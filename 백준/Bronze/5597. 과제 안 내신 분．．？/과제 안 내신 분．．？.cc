#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool cheak[31];

    for(int i=1;i<31;i++) {
        cheak[i] = false;
    }

    int n;
    for(int i=0;i<28;i++)
    {
        cin >> n;
        cheak[n] = true;
    }

    for(int i=1;i<31;i++) {
        if(!cheak[i])
            cout << i << "\n";
    }

    return 0;
}