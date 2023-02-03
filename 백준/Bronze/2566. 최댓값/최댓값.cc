#include<stdio.h>
main(){int m=0,k,n,i;for(i=0;i<81;i++){scanf("%d",&k);if(k>=m){m=k;n=i;}}printf("%d\n%d %d",m,n/9+1,n%9+1);}