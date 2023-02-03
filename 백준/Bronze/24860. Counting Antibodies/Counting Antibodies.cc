#include <iostream>

using namespace std;

int main() {
    long long Vk, Jk, Vl, Kl, Vh, Dh, Jh, ret;
    
    cin >> Vk >> Jk;
    cin >> Vl >> Kl;
    cin >> Vh >> Dh >> Jh;
    
    ret = (Vk * Jk) * (Vh * Dh * Jh) + (Vl * Kl) * (Vh * Dh * Jh);
    
    cout << ret;
    
    return 0;
}