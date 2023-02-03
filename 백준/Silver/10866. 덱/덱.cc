#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int deque[30000], head=15000, tail=15000;

int main() {
    int N;
    scanf("%d",&N);
    memset(deque, -1, 30000*sizeof(int));
    
    while(N--) {
        int num;
        char str[100];
        scanf("%s",str);
        if(str[0]=='p' && str[1]=='u') {
            if(str[5]=='f') { // push_front
                scanf("%d",&num);
                deque[--head]=num;
            }
            else { // push_back
                scanf("%d",&num);
                deque[tail++]=num;
            }
        }
        else if(str[0]=='p' && str[1]=='o') {
            if(str[4]=='f') { // pop_front
                if(head==tail) {
                    printf("-1\n");
                }
                else {
                    printf("%d\n",deque[head++]);
                }
            }
            else { // pop_back
                if(head==tail) {
                    printf("-1\n");
                }
                else {
                    printf("%d\n",deque[--tail]);
                }
            }
        }
        else if(str[0]=='s') { // size
            printf("%d\n",tail-head);
        }
        else if(str[0]=='e') { // empty
            if(head==tail) {
                printf("1\n");
            }
            else {
                printf("0\n");
            }
        }
        else if(str[0]=='f') { // front
            if(head==tail) {
                printf("-1\n");
            }
            else {
                printf("%d\n",deque[head]);
            }
        }
        else { // back
            if(head==tail) {
                printf("-1\n");
            }
            else {
                printf("%d\n",deque[tail-1]);
            }
        }
    }
    
    return 0;
}