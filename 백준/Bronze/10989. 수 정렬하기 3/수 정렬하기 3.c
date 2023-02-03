# include <stdio.h>

int main()
{
    int N, i, j, k, answer[10001] = {0,};
    
    scanf("%d",&N); //입력부
    
    for(i=0;i<N;i++){
        scanf("%d",&k);
        answer[k] += 1;
    }  
    
    for(i=1;i<10001;i++){ //출력부
        for(j=0;j<answer[i];j++){
            printf("%d\n",i);
        }
    }
    
    return 0;
}