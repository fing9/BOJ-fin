#include <stdio.h>
#define PI 3.1415926535897932384

int main(){
    int R;
    scanf("%d",&R);
    printf("%lf\n",(PI)*(double)(R*R));
    printf("%lf",(double)(R*2*R));
    return 0;
}