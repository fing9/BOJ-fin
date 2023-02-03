#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <utility>
#include <complex>

using namespace std;

int N, M, num;
vector<pair<int, pair<int, int>>> v; // {추천 횟수, {게시 시간, 학생 번호}}
vector<pair<int, pair<int, int>>> ret; // {학생 번호, {추천 횟수, 게시 시간}}

bool compare(pair<int, pair<int, int>> a,  pair<int, pair<int, int>> b) {
    if(a.first < b.first) return true;
    else if(a.first == b.first) {
        if(a.second.first < b.second.first) return true;
    }

    return false;
}

int main() {
    scanf("%d\n%d", &N, &M);

    for(int i=0;i<M;i++) {
        scanf("%d", &num);

        int idx = 0;
        bool isIn = false;
        for(int j=0;j<v.size();j++) {
            if(v[j].second.second == num) {
                isIn = true;
                idx = j;
                break;
            }
        }

        if(isIn) {
            v[idx].first++;
        }
        else {
            if (v.size() < N) {
                v.push_back({1, {i, num}});
            }
            else {
                if(!v.empty()) {
                    v[0].first = 1;
                    v[0].second.first = i;
                    v[0].second.second = num;
                }
                else {
                    v.push_back({1, {i, num}});
                }
            }
        }

        sort(v.begin(), v.end(), compare);
    }

    for(int i=0;i<v.size();i++) {
        ret.push_back({v[i].second.second, {v[i].first, v[i].second.first}});
    }

    sort(ret.begin(), ret.end());

    for(int i=0;i<ret.size();i++) {
        printf("%d ", ret[i].first);
    }

    return 0;
}