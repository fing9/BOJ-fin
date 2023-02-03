#include <stdio.h>

int main(){
    int A, B, V, count = 0, where;
    
    scanf("%d %d %d",&A,&B,&V);
    
    if(A == V){
        printf("%d",1);
        return 0;
    }
    
    count = (V-A)/(A-B);
    where = V-(count*(A-B));
    
    if(where == 0){
        printf("%d",count);
    }
    else if(where<=A){
        printf("%d",count+1);
    }
    while(where>A){
        where -= A;
        count += 1;
        if(where<A){
            printf("%d",count+1);
            return 0;
        }
        else if(where==A){
            printf("%d",count);
            return 0;
        }
        where += B;
    }
    return 0;
}