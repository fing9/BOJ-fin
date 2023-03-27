#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <string.h>

#define INF 987654321
#define ll long long

using namespace std;

char str[600000];
int n;

void init(int cnt) {
    for (int i=0;i<=cnt;i++) {
        str[i] = '-';
    }
}

void fill(int s, int e) {
    if (s == e - 1|| s == e) return ;
    int p1 = s + ((e - s) / 3);
    int p2 = s + (((e - s) / 3) * 2);

    //printf("s:%d  e:%d  p1:%d  p2:%d\n", s, e, p1, p2);
    for (int i=p1;i<p2;i++) {
        str[i] = ' ';
    }
    fill(s, p1);
    fill(p1, p2);
    fill(p2, e);
}

void print(int cnt) {
    for (int i=0;i<cnt;i++) {
        printf("%c", str[i]);
    }
    printf("\n");
}

int main() {
    while(scanf("%d", &n) != EOF) {
        init(pow(3,n));
        fill(0,pow(3,n));
        print(pow(3,n));
    }

    return (0);
}