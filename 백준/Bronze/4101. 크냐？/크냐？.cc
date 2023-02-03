#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    int a, b;
    scanf("%d %d", &a, &b);
    while(!(a==0 && b==0))
    {
        if(a==b)
            printf("No\n");
        else if(a == max(a,b))
            printf("Yes\n");
        else
            printf("No\n");
        scanf("%d %d", &a, &b);
    }

    return 0;
}
