#include <stdio.h>

int main(){
    int x, y, z, tmp;
    
    scanf("%d %d %d",&x,&y,&z);
    
    if(x>y){
        tmp = x;
        x = y;
        y = tmp;
    }
    if(y>z){
        tmp = y;
        y = z;
        z = tmp;
    }
    if(x>y){
        tmp = x;
        x = y;
        y = tmp;
    }
    
    while(x!=0||y!=0||z!=0){
        if((x*x)+(y*y) == (z*z)){
            printf("right\n");
        }
        else{
            printf("wrong\n");
        }
        scanf("%d %d %d",&x,&y,&z);
        if(x>y){
            tmp = x;
            x = y;
            y = tmp;
        }
        if(y>z){
            tmp = y;
            y = z;
            z = tmp;
        }
        if(x>y){
            tmp = x;
            x = y;
            y = tmp;
        }
    }
    
    return 0;
}