# include <stdio.h>

int fibonacci(int n){
    if(n > 1){
        return fibonacci(n-1) + fibonacci(n-2);
    }
    else if(n == 0){
        return 0;
    }
    else{
        return 1;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d",fibonacci(n));
    return 0;
}