#include <stdio.h>

int main(){
    int x, y, w, h, length = 10000;
    scanf("%d %d %d %d",&x,&y,&w,&h);
    if(length>(w-x)){
        length = w-x;
    }
    if(length>x){
        length = x;
    }
    if(length>(h-y)){
        length = h-y;
    }
    if(length>y){
        length = y;
    }
    printf("%d",length);
    return 0;
}