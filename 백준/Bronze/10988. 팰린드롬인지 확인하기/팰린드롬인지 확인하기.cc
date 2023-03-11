#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

#define INF 987654321

using namespace std;

int main() {
    char word[101];
    int j;

    scanf("%s", word);
    j = strlen(word) - 1;
    for (int i=0;i<j;i++,j--) {
        if (word[i] != word[j]) {
            printf("0");
            return (0);
        }
    }

    printf("1");
    return 0;
}