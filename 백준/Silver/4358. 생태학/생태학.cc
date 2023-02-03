#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cmath>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <deque>
#include <map>
#define INF 1987654321

using namespace std;

int main()
{
	string str;
	map<string, int> mp;
	float cnt = 0;

	while (getline(cin, str)) {
		cnt++;
		mp[str]++;
	}

	float val;
	// 이터레이터 사용법
	for (auto it = mp.begin(); it != mp.end(); it++) {
		val = (it->second * 100) / cnt;
		printf("%s %.4f\n", it->first.c_str(), val);
	}


	return 0;
}