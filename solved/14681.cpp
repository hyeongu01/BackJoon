/*
    https://www.acmicpc.net/problem/14681

    사분면 판단하기
*/
#include <iostream>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    if (x > 0) {
        cout << (y > 0 ? 1 : 4) << endl;
    } else {
        cout << (y > 0 ? 2 : 3) << endl;
    }

    return 0;
}