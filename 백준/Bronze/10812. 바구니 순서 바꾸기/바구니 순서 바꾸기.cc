#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

#define INF 987654321

using namespace std;

int arr[101];
int N, M;

void init() {
    for (int i=0;i<=100;i++) {
        arr[i] = i;
    }
}

int main() {

    init();

    scanf("%d %d", &N, &M);
    for (int l=0;l<M;l++) {
        vector<int> v;
        int begin, end, mid;

        scanf("%d %d %d", &begin, &end, &mid);
        for (int i=mid;i<=end;i++) {
            v.push_back(arr[i]);
        }
        for (int i=begin;i<=mid - 1;i++) {
            v.push_back(arr[i]);
        }
        for (int i=0;i<v.size();i++) {
            arr[begin++] = v[i];
        }
    }

    for (int i=1;i<=N;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return (0);
}