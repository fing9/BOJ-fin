#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
int sorted[500001];
long long swaped = 0;

void merge(int *arr, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    priority_queue<int> vL, vR;

    while(i<=mid && j<=right) {
        if(arr[i] <= arr[j]) {
            sorted[k] = arr[i];
            vL.push(k);
            k++;
            i++;
        }
        else {
            sorted[k] = arr[j];
            vR.push(k);
            k++;
            j++;
        }
    }

    while(i<=mid) {
        sorted[k] = arr[i];
        vL.push(k);
        k++;
        i++;
    }

    while(j<=right) {
        sorted[k] = arr[j];
        vR.push(k);
        k++;
        j++;
    }

    for(int i=left;i<=right;i++) {
        arr[i] = sorted[i];
    }

    while(!vL.empty()) {
        if(vR.empty()) {
            break;
        }
        if(vL.top() >= vR.top()) {
            swaped += vR.size();
            vL.pop();
        }
        else {
            vR.pop();
        }
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
    int N, arr[500001];
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        scanf("%d", &arr[i]);
        sorted[i] = arr[i];
    }

    merge_sort(arr, 0, N-1);

    printf("%lld", swaped);

    return 0;
}