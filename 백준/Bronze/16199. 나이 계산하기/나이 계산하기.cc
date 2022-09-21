#include <iostream>

using namespace std;

int main() {
    int yB, mB, dB;
    int yN, mN, dN;
    int ans1, ans2, ans3;
    
    cin >> yB >> mB >> dB;
    cin >> yN >> mN >> dN;
    
    if((mN > mB) || (mN == mB && dN >= dB)) ans1 = yN - yB;
    else ans1 = yN - yB - 1;
    ans2 = yN - yB + 1;
    ans3 = yN - yB; 
    
    cout << ans1 << "\n";
    cout << ans2 << "\n";
    cout << ans3 << "\n";
    
    return 0;
}