/*
    https://www.acmicpc.net/problem/1476
*/

#include <iostream>

using namespace std;

int main() {
    int e, s, m;
    cin >> e >> s >> m;
    e --; s --; m --;
    int result = e;

    while(true) {
        if (result % 28 == s) break;
        result += 15;
    }
    while (true) {
        if (result % 19 == m) break;
        result += 15*28;
    }
    cout << result + 1 << endl;

    return 0;
}