#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <string>

//ㅇ 수진 영빈
// 이화사거리

using namespace std;
int sorted[500001], now = 0, ret = -1, K;

void merge(int *arr, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    priority_queue<int> vL, vR;

    while(i<=mid && j<=right) {
        if(arr[i] <= arr[j]) {
            sorted[k++] = arr[i++];
        }
        else {
            sorted[k++] = arr[j++];
        }
    }

    while(i<=mid) {
        sorted[k++] = arr[i++];
    }

    while(j<=right) {
        sorted[k++] = arr[j++];
    }

    for(int i=left;i<=right;i++) {
        //cout << sorted[i] << " ";
        if(++now == K) ret = sorted[i];
        arr[i] = sorted[i];
    }
}

void merge_sort(int *arr, int left, int right) {
    int mid = (left + right) / 2;

    if(left != right) {
        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, arr[500001] = {0,};
    cin >> N >> K;

    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }

    merge_sort(arr, 0, N-1);

    cout << ret;

    return 0;
}