#include <iostream>
using namespace std;
long long N, lastprice, disSum = 0, ret = 0;
long long dist[100000];
long long price[100001];

int main() {
	scanf("%lld", &N);
	for(int i=0;i<N-1;i++) {
		scanf("%lld", &dist[i]);
	}
	for(int i=0;i<N;i++) {
		scanf("%lld", &price[i]);
	}
	
	lastprice = price[0];
	
	for(int i=0;i<N-1;i++) {
		disSum += dist[i];
		if(lastprice > price[i+1])
		{
			ret += lastprice*disSum;
			disSum = 0;
			lastprice = price[i+1];
		}
		else if(i==N-2)
		{
			ret += lastprice*disSum;
			disSum = 0;
			lastprice = price[i+1];
		}
	}
	
	printf("%lld",ret);
	
	return 0;
}