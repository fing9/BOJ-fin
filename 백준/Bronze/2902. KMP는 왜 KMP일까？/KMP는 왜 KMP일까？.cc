#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    char arr[101], ret[101];
    int l=0, k=0;
    bool run=true;
    scanf("%s",arr);
    while(arr[l]!=NULL) {
        if(run) {
            ret[k++] = arr[l];
            run=false;
        }
        else {
            if(arr[l]=='-')
                run=true;
        }
        l++;
    }
    for(int i=0;i<k;i++)
        printf("%c",ret[i]);
    
    return 0;
}