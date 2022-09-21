int main(){
    long long T, x, y, i, all, length, answer, pattern;
    
    scanf("%d",&T);
    
    for(i=0;i<T;i++){
        answer = 0;
        pattern = 1;
        all = 2;
        
        scanf("%lld %lld",&x,&y);
        
        length = y-x;
        if(length == 1){
            printf("1\n");
        }
        else if(length == 0){
            printf("0\n");
        }
        else{
            while(length>all){
                if(length>all){
                    pattern += 1;
                    all += 2*pattern;
                    answer += 2;
                }
            }
            if(all-length >= pattern){
                printf("%lld\n",answer+1);
            }
            else{
                printf("%lld\n",answer+2);
            }
        }
    }
    
    return 0;
}