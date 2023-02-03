#include <stdio.h>

int main(){
    int T,H,W,N,i,j,room[1][2];
    
    scanf("%d",&T);
    
    for(i=0;i<T;i++){
        scanf("%d %d %d",&H,&W,&N);
        
        if(H == 1 && W != 1){
            room[0][1] = N/H;
            if(room[0][1]<10){
                printf("10%d\n",room[0][1]);
            }
            else{
                printf("1%d\n",room[0][1]);
            }
        }
        else if(W == 1){
            room[0][0] = N;
            printf("%d01\n",room[0][0]);
        }
        else{ //일반적인경우
            if(N%H != 0){
                room[0][0] = N%H;
                room[0][1] = 1+(N/H);
            }
            else{
                room[0][0] = H;
                room[0][1] = N/H;
            }
            
            if(room[0][1]<10){
                printf("%d0%d\n",room[0][0],room[0][1]);
            }
            else{
                printf("%d%d\n",room[0][0],room[0][1]);
            }
        }
    }
    return 0;
}