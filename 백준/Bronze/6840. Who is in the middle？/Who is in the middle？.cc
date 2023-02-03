#include <iostream>
#include <queue>

using namespace std;

int main() {
    int a, b, c;
    priority_queue<int> pq;
    
    scanf("%d\n%d\n%d", &a, &b, &c);
    pq.push(a);
    pq.push(b);
    pq.push(c);
    pq.pop();
    printf("%d",pq.top());
    
    return 0;
}