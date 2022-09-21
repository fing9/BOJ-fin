#include <iostream>

using namespace std;

int main()
{
    int arr[5], max[2];
    
    max[0] = -1;
    max[1] = -1;
    for(int i=0;i<5;i++) {
        arr[i] = 0;
    }
    
    for(int i=0;i<5;i++) {
        int d;
        for(int j=0;j<4;j++) {
            scanf("%d", &d);
            arr[i] += d;
        }
        if(arr[i] > max[1]) {
            max[0] = i+1;
            max[1] = arr[i];
        }
    }
    
    printf("%d %d", max[0], max[1]);
    
    return 0;
}