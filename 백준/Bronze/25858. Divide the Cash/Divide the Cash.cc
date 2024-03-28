#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int N, M;
vector<int> points;

int main() {
    scanf("%d %d", &N, &M);
    int sum = 0;
    for (int i=0;i<N;i++) {
        int inp;

        scanf("%d", &inp);
        sum += inp;
        points.push_back(inp);
    }
    for (int i=0;i<N;i++) {
        printf("%d\n", points[i] * (M / sum));
    }
    return 0;
}