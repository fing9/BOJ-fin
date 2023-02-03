#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;

int main() {
    int N, M, cnt=0;
    scanf("%d %d",&N,&M);
    deque<int> dq;
    
    for(int i=1;i<=N;i++) {
        dq.push_back(i);
    }
    
    for(int i=0;i<M;i++) {
        int num;
        scanf("%d",&num);
        
        if(dq.front()==num) {
            dq.pop_front();
        }
        else {
            int target;
            for(int j=0;j<dq.size();j++) {
                if(dq[j]==num) {
                    target = j;
                }
            }
            if(dq.size()-target <= target) {
                for(int k=0;k<dq.size()-target;k++) {
                    dq.push_front(dq.back());
                    dq.pop_back();
                    cnt++;
                }
                dq.pop_front();
            }
            else {
                for(int k=0;k<target;k++) {
                    dq.push_back(dq.front());
                    dq.pop_front();
                    cnt++;
                }
                dq.pop_front();
            }
        }
    }
    
    printf("%d",cnt);
    
    return 0;
}