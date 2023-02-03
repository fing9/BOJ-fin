# include <stdio.h>

int main(){
    int N, ori, sum, i, pronum[2000001];
    for(i=0;i<=2000000;i++){
        pronum[i] = 2000000;
    }
    for(i=1;i<=1000000;i++){
        ori = i;
        sum = i;
        while(ori>0){
            sum += ori%10;
            ori /= 10;
        }
        if(pronum[sum]>i){
            pronum[sum]=i;
        }
    }
    
    scanf("%d",&N);
    if(pronum[N] != 2000000)
        printf("%d",pronum[N]);
    else
        printf("0");
    return 0;
}