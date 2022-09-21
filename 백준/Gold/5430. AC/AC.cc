#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
using namespace std;
bool mode=true; //true가 왼쪽에서부터 false가 오른쪽에서부터

void rvs() {
    if(mode==true) {
        mode=false;
        return;
    }
    else {
        mode=true;
        return;
    }
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        char str[100002], num[500000];
        int N, endad=0;
        bool er=false;
        deque<int> dq;
        mode=true;
        
        memset(num,NULL,sizeof(num));
        scanf("%s",str);
        scanf("%d",&N);
        scanf("%s",num);
        
        if(N!=0) // 입력부
        {
            for(int i=0;i<sizeof(num);i++) {
                if(num[i]=='[' || num[i]==',') {
                    dq.push_back(atoi(&num[i+1]));
                }
                else if(num[i]==']') break;
            }
        }
        
        for(int i=0;i<sizeof(str);i++) {
            if(str[i]=='R') {
                rvs();
            }
            else if(str[i]=='D') {
                if(dq.size()!=0) {
                    if(mode==true) dq.pop_front();
                    else dq.pop_back();
                }
                else {
                    printf("error\n");
                    er=true;
                    break;
                }
            }
            else break;
        }
        
        if(er) continue;
        
        int dqnum=dq.size();
        printf("["); // 출력부
        if(mode==true) {
            for(int i=0;i<dqnum;i++) {
                printf("%d",dq.front());
                dq.pop_front();
                if(i!=dqnum-1) printf(",");
            }
        }
        else {
            for(int i=0;i<dqnum;i++) {
                printf("%d",dq.back());
                dq.pop_back();
                if(i!=dqnum-1) printf(",");
            }
        }
        printf("]\n");
    }
    
    return 0;
}