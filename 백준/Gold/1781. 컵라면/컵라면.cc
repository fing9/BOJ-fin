#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <utility>
#include <queue>
#include <stack>

using namespace std;

struct compare{
    bool operator()(pair<int,int> a, pair<int,int> b){
        if(a.first > b.first) return true;
        else if(a.first < b.first) return false;
        else {
            if(a.second < b.second) return true;
            else return false;
        }
    }
};

struct compare2{
    bool operator()(pair<int,int> a, pair<int,int> b){
        if(a.second > b.second) return true;
        else if(a.second < b.second) return false;
        else {
            if(a.first < b.first) return true;
            else return false;
        }
    }
};

int main() {
    priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
    priority_queue<pair<int,int>, vector<pair<int,int>>, compare2> pq2;
    int N, now = 0;
    long long ret = 0;
    scanf("%d", &N);

    for(int i=0;i<N;i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        pq.push({a,b});
    }

    for(int i=0;i<N;i++) {
        //printf("%d %d\n", pq.top().first, pq.top().second);
        if(now < pq.top().first) {
            ret += pq.top().second;

            pq2.push(pq.top());
            now++;
        }
        else if(!pq2.empty()) {
            if (pq.top().second > pq2.top().second) {
                ret += pq.top().second;
                ret -= pq2.top().second;

                pq2.pop();
                pq2.push(pq.top());
            }
        }
        pq.pop();
    }

    printf("%lld", ret);

    return 0;
}