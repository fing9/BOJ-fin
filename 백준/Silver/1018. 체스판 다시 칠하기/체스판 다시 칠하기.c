# include <stdio.h>

int main(){
    int M, N, i, j, k, l, answer_1 = 0, answer_2 = 0, trueanswer=10000;
    
    scanf("%d %d",&N,&M);
    char board[N][M];
    
    for(i=0;i<N;i++){
        scanf("%s",&board[i][0]);
    }
    
    for(k=0;k<N-7;k++){
        for(l=0;l<M-7;l++){
            for(i=k;i<8+k;i++){ //경우의 수 1
                if(i%2==0){
            	    for(j=l+1;j<8+l;j+=2){
                        if(board[i][j]=='W')
                            answer_1++;
            	    }
                }
                else{
            	    for(j=l;j<8+l;j+=2){
                        if(board[i][j]=='W')
                            answer_1++;
            	    }
                }
            }
            for(i=k;i<8+k;i++){ //경우의 수 1_2
                if(i%2==0){
            	    for(j=l;j<8+l;j+=2){
                        if(board[i][j]=='B')
                            answer_1++;
            	    }
                }
                else{
            	    for(j=l+1;j<8+l;j+=2){
                        if(board[i][j]=='B')
                            answer_1++;
            	    }
                }
            }
            
            for(i=k;i<8+k;i++){ //경우의 수 2
                if(i%2==0){
            	    for(j=l+1;j<8+l;j+=2){
                        if(board[i][j]=='B')
                            answer_2++;
            	    }
                }
                else{
            	    for(j=l;j<8+l;j+=2){
                        if(board[i][j]=='B')
                            answer_2++;
            	    }
                }
            }
            for(i=k;i<8+k;i++){ //경우의 수 2_2
                if(i%2==0){
            	    for(j=l;j<8+l;j+=2){
                        if(board[i][j]=='W')
                            answer_2++;
            	    }
                }
                else{
            	    for(j=l+1;j<8+l;j+=2){
                        if(board[i][j]=='W')
                            answer_2++;
            	    }
                }
            }
            if(trueanswer > answer_1){
                trueanswer = answer_1;
            }
            if(trueanswer > answer_2){
                trueanswer = answer_2;
            }
            answer_1 = 0;
            answer_2 = 0;
        }
    }
    
    printf("%d",trueanswer);
    return 0;
}