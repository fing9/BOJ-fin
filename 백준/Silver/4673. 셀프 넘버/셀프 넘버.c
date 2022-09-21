#include <stdio.h>

int d(int n){
    int sum;
    
    sum = n + (n%10);
    while(n>=10){
        n /= 10;
        sum += n%10;
    }
    
    return sum;
}

int main(){
    int i;
    int answer[15000] ={0,};
    
    for(i=1;i<=10000;i++){
        answer[d(i)-1] = 1;
    }
    
    for(i=0;i<10000;i++){
        if(answer[i] == 0){
            printf("%d\n",i+1);
        }
    }
    
    return 0;
}