# include <stdio.h>
# include <math.h>

int main(){
    int T, x1, y1, r1, x2, y2, r2, i;
    double length;
    
    scanf("%d",&T);
    
    for(i=0;i<T;i++){
        scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);
        length = sqrt((double)(abs(x1-x2)*abs(x1-x2)) + (double)(abs(y1-y2)*abs(y1-y2)));
        if(length == 0 && r1 == r2){
            printf("-1\n");
        }
        else if(length == r1+r2 || r1+length == r2 || fabs(length-r1) == r2 || r2+length == r1 || fabs(length-r2) == r1){
            printf("1\n");
        }
        else if(length < r1+r2 && r1+length > r2 && fabs(length-r1) < r2 && r2+length > r1 && fabs(length-r2) < r1){
            printf("2\n");
        }
        else{
            printf("0\n");
        }
    }
    return 0;
}