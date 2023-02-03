# include <stdio.h>

int main(){
    int N, i, Num[100000], count=1, judge;
    
    for(i=666;i<10000000;i++){ //그냥 무식하게 풀어버리기~
        judge=i;
        while(judge>=666){
            if(judge%1000==666){
                Num[count++]=i;
                judge = 0;
            }
            else{
                judge/=10;
            }
        }
    }
    
    scanf("%d",&N);
    printf("%d",Num[N]);
    
    return 0;
}