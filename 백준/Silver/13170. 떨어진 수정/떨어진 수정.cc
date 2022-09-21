#include <iostream>

using namespace std;

int main()
{
    int N, K, P, W, ans;

    scanf("%d %d %d %d", &N, &K, &P, &W);

    ans = (P / W);
    if(P%W != 0) ans++;

    printf("%d", ans);
    
    return 0;
}