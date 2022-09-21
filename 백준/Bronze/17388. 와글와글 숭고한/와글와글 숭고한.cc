#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <cmath>

#define INF 987654321

using namespace std;

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    int s, g, h;
    scanf("%d %d %d", &s, &g, &h);

    if(s+g+h >=100) {
        printf("OK");
    }
    else if(min(s,min(g,h)) == s) {
        printf("Soongsil");
    }
    else if(min(s,min(g,h)) == g) {
        printf("Korea");
    }
    else if(min(s,min(g,h)) == h) {
        printf("Hanyang");
    }

    return 0;
}