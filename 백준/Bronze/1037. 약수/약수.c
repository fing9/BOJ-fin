# include <stdio.h>
int main(){
    int N,k,m=0,b=1000001;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&k);
        if(k>m) m=k;
        if(k<b) b=k;
    }
    printf("%d",m*b);
    return 0;
}