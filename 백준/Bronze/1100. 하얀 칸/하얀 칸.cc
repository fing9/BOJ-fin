#include <cstdio>
int main(){char a[9];int r=0;for(int i=0;i<8;i++){std::scanf("%s",a);for(int j=0;j<8;j++){if(a[j]=='F'&&(i+j)%2==0)r++;}}std::printf("%d",r);return 0;}