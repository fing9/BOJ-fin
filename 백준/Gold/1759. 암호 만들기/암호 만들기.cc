#include <iostream>
#include <algorithm>

using namespace std;

int L,C;
char buffer[2];

char * a; // 문자의 종류를 저장 
int * current; // 문자열의 각 문자의 위치를 저장 
int * limit; //문자열의 각 위치의 한계점 위치를 저장 

bool checkChar(char c) { //모음 -> false 자음 -> true
	if(c == 'a' || c == 'e' || c == 'u' || c == 'i' || c == 'o')
		return false;
	return true;
}

void printPassword() {
	int v = 0 , c = 0;
	
	for(int x = 1 ; x <= L ; x++) {
		if(checkChar(a[current[x]]))
			c++;
		else 
			v++;	
	}
	
//	cout << "v : " << v << " c : " << c << endl;
//	for(int x = 1 ; x <= L ; x++) {
//			cout << a[current[x]];
//		}
//	cout << "\n";
	if(v >= 1 && c >= 2) {
		//cout << "v : " << v << " c : " << c << endl; 
		for(int x = 1 ; x <= L ; x++) {
			cout << a[current[x]];
		}
		cout << "\n";
	}
}

void makePassword(int n){ //n은 문자열에서 인덱스 
	//다음 위치로 넘어가거나 암호를 출력해야함.
	if(n == L + 1) { //출력 --> 맨 마지막에 닿았을때 
			printPassword();
	}
	
	else { // 다음 문자열 인덱스로 넘어가야할때  
		for(int x = current[n-1] + 1 ; x <= limit[n] ; x++) { //current[n]을 결정함. 
			current[n] = x;
			makePassword(n+1);
		}
	} 
}

int main()
{	
	cin >> L >> C; //L : 문자열 길이, C : 출력 가능 문자 종류 갯수
	
	a = new char[C];
	current = new int[L+1];
	limit = new int[L+1];
	 
	for(int x = 0 ; x < C ; x++) {
	
		cin >> buffer;
		a[x] = buffer[0];
	}
	sort(a,a+C);
	for(int x = 0 ; x < L ; x++) {
		limit[x+1] = (C - 1) - (L - (x+1));  
	} // limit 계산 
	current[0] = -1; 
	 makePassword(1);
}

//testcode (질문한사람 코드임)