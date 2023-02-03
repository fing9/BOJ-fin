#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>

using namespace std;

void printTime(int Hs,int Ms,int Ss,int He,int Me,int Se)
{
    int H, M, S;
    H = He - Hs;
    M = Me - Ms;
    S = Se - Ss;

    if(S < 0) {
        M--;
        S += 60;
    }
    if(M < 0) {
        H--;
        M += 60;
    }

    cout << H << " " << M << " " << S << '\n';
}

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    int aHs, aMs, aSs, aHe, aMe, aSe;
    int bHs, bMs, bSs, bHe, bMe, bSe;
    int cHs, cMs, cSs, cHe, cMe, cSe;

    scanf("%d %d %d %d %d %d",&aHs, &aMs, &aSs, &aHe, &aMe, &aSe);
    scanf("%d %d %d %d %d %d",&bHs, &bMs, &bSs, &bHe, &bMe, &bSe);
    scanf("%d %d %d %d %d %d",&cHs, &cMs, &cSs, &cHe, &cMe, &cSe);

    printTime(aHs, aMs, aSs, aHe, aMe, aSe);
    printTime(bHs, bMs, bSs, bHe, bMe, bSe);
    printTime(cHs, cMs, cSs, cHe, cMe, cSe);

    return 0;
}