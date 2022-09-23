#include <iostream>
using namespace std;
unsigned long long test[3] = {2, 7, 61};

// power는 x^y의 계산 결과를 return (빠른 거듭제곱)
unsigned long long power(unsigned long long x, unsigned long long y, unsigned long long mod)
{
	unsigned long long res = 1;
	x %= mod;
	while(y)
	{
		if(y%2) res = (res * x) % mod;
		y /= 2;
		x = (x*x) % mod;
	}
	return res;
}

bool miller(unsigned long long n, unsigned long long a)
{
	if(a % n == 0) return true;
	unsigned long long k = n - 1;
	while(1)
	{
		unsigned long long temp = power(a, k, n);
		if(temp == n-1) return true;
		if(k%2) return (temp == 1 || temp == n-1);
		k /= 2;
	}
}

int main() {
	int N, ans=0;
	unsigned long long a;
	
	scanf("%d", &N);
	
	for(int i=0;i<N;++i)
	{
		scanf("%llu", &a);
		a = a * 2 + 1;
		
        for(int j=0;j<3;j++)
        {
		    if(!miller(a, test[j]))
		    {
			    ans++;
			    break;
		    }
        }
	}
	
	printf("%d", N-ans);
	
	return 0;
}