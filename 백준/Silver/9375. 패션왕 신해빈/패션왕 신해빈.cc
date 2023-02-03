#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int T, N, typenum=0, answer=1, dress_type_num[31];
    char dress[31][22], dress_name[22], dress_type[22];
    bool is_ex=false;
    scanf("%d",&T);
    
    for(int i=0;i<T;++i)
    {
        typenum=0;
        answer=1;
        is_ex=false;
        
        for(int l=0;l<31;l++)
            dress_type_num[l]=0;
        
        scanf("%d",&N);
        for(int j=0;j<N;++j)
        {
            scanf("%s",dress_name);
            scanf("%s",dress_type);
            for(int l=0;l<typenum;l++)
            {
                if(strcmp(dress_type, dress[l]) == 0)
                {
                    is_ex=true;
                    dress_type_num[l]++;
                    break;
                }
            }
            if(is_ex==false)
            {
                dress_type_num[typenum]++;
                strcpy(dress[typenum++], dress_type);
            }
            is_ex=false;
        }
        
        for(int l=0;l<31;l++)
        {
            if(dress_type_num[l]!=0)
            {
                answer*=dress_type_num[l]+1;
            }
        }
        
        printf("%d",answer-1);
        if(i!=T-1)
            printf("\n");
    }
    
    return 0;
}