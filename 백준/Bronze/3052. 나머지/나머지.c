#include <stdio.h>

int main()
{
    int i, j, dff = 10, same = 0;
    int arr_1[10] = {0,0,0,0,0,0,0,0,0,0};
    
    for(i=0;i<10;i++){
        scanf("%d",&arr_1[i]);
        arr_1[i] %= 42;
    }
    
    for(i=0;i<10;i++){
        for(j=i;j<9;j++){
            if(arr_1[i] == arr_1[j+1]){
                same += 1;
                j = 10;
            }
        }
        dff -= same;
        same = 0;
    }
    
    printf("%d",dff);
    
    return 0;
}