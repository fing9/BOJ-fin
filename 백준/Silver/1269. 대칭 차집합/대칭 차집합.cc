#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B;
    int inpA, inpB, cnt = 0;
    map<int, int> m;

    cin >> A >> B;
    for(int i=0;i<A;i++)
    {
        cin >> inpA;
        m.insert({inpA,1});
    }
    for(int i=0;i<B;i++)
    {
        cin >> inpB;
        if(m.find(inpB) != m.end()) cnt++;
    }

    cout << A+B-(2*cnt);

    return 0;
}
