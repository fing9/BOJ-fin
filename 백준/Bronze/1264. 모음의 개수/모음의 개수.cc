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

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    while(1)
    {
        char c;

        scanf("%c", &c);
        int cnt = 0, i = 1;
        while(c != '\n')
        {
            if(c == '#')
                return 0;

            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                cnt++;
            else if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
                cnt++;
            scanf("%c", &c);
            i++;
        }


        printf("%d\n", cnt);
    }
    
    return 0;
}