#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string A, B, C;
    cin >> A >> B >> C;

    int numA, numB, numC;
    int numAB;
    stringstream(A) >> numA;
    stringstream(B) >> numB;
    stringstream(C) >> numC;
    stringstream(A + B) >> numAB;

    printf("%d\n%d", (numA + numB - numC), (numAB - numC));
}