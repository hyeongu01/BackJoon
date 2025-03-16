/*
    https://www.acmicpc.net/problem/2420
*/

#include <iostream>

using namespace std;

int main() {
    long long  a, b;
    cin >> a >> b;
    cout << (a-b >= 0 ? a-b : b-a) << endl;

    return 0;
}