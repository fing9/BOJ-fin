#include <stdio.h>

int main(){
    int x_1, y_1, x_2, y_2, x_3, y_3, x, y;
    scanf("%d %d",&x_1,&y_1);
    scanf("%d %d",&x_2,&y_2);
    scanf("%d %d",&x_3,&y_3);
    if(x_1 != x_2 && x_1 != x_3)
        x = x_1;
    if(x_2 != x_3 && x_2 != x_1)
        x = x_2;
    if(x_3 != x_2 && x_3 != x_1)
        x = x_3;
    if(y_1 != y_2 && y_1 != y_3)
        y = y_1;
    if(y_2 != y_3 && y_2 != y_1)
        y = y_2;
    if(y_3 != y_2 && y_3 != y_1)
        y = y_3;
    printf("%d %d",x,y);
    return 0;
}