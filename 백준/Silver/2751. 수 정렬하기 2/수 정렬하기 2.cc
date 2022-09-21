#include <iostream>
using namespace std;
int sorted[1000001], swap = 0;

void merge(int *arr, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    
    while(i<=mid && j<=right) {
        if(arr[i] <= arr[j]) {
            sorted[k++] = arr[i];
            i++;
        }
        else {
            sorted[k++] = arr[j];
            j++;
        }
    }
    
    while(i<=mid) {
        sorted[k++] = arr[i];
        i++;
    }
    
    while(j<=right) {
        sorted[k++] = arr[j];
        j++;
    }
    
    for(int i=left;i<=right;i++) {
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
    int N, arr[1000001];
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        scanf("%d", &arr[i]);
        sorted[i] = arr[i];
    }
    
    merge_sort(arr, 0, N-1);
    
    for(int i=0;i<N;i++) {
        printf("%d ", sorted[i]);
    }
    
    return 0;
}