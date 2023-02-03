#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
long long count=0;
vector<pair<int, int> > v;

// 코드 긴빠이 출처:https://jaimemin.tistory.com/732
string bigNumAdd(string num1, string num2)
{
        long long sum = 0;
        string result;

        while (!num1.empty() || !num2.empty() || sum)
        {
                 if (!num1.empty())
                 {
                         sum += num1.back() - '0';
                         num1.pop_back();
                 }
                 if (!num2.empty())
                 {
                         sum += num2.back() - '0';
                         num2.pop_back();
                 }
            
                 //다시 string 형태로 만들어 push_back
                 result.push_back((sum % 10) + '0');
                 sum /= 10;
        }

        //1의 자리부터 result에 넣었으므로 뒤집어줘야한다
        reverse(result.begin(), result.end());
        return result;
}

//2의 n승은 0으로 끝날 수 없으므로
string subtractOne(string num)
{
        vector<int> v;
        int back = num.back() - '0';
        num.pop_back();
        back -= 1;
        num.push_back(back + '0');
    
        return num;
}


void hanoi(int N, int from, int tmp, int to)
{
	//base case
	if(N==1)
	{
        v.push_back(make_pair(from, to));
		return;
	}
	
	hanoi(N-1, from, to, tmp);
	hanoi(1, from, tmp, to);
	hanoi(N-1, tmp, from, to);
	
	return;
}

int main(void) {
	int N;
	
	cin >> N;
	
    if(N <= 20)
    {
         hanoi(N, 1, 2, 3);
         cout << v.size() << "\n";
         for (int i = 0; i < v.size(); i++)
             cout << v[i].first << " " << v[i].second << "\n";
    }
    else
    {
        string num = "2";
        for (int i = 0; i < N - 1; i++)
        {
             string temp = bigNumAdd(num, num);
             num = temp;
        }
        cout << subtractOne(num) << "\n";
    }
    
	return 0;
}