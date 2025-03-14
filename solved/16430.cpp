/*
    https://www.acmicpc.net/problem/16430

    기약분수로 나타내는것이 문제!
     - 1~9범위니 일일히 확인하여 나눌까?

     A = 3, B = 7일 때
     1*7 - 3 = 4
     4/7;

     A = 6, B = 8;
     8-6 = 2;
     2/8 -> 1/4;

    1~9 사이의 소수: 2, 3, 5, 7
    4개이니 그냥 일일히 확인하자!
*/

#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int p = b-a;
    int q = b;

    int list[4] = {2, 3, 5, 7};

    for (int x: list) {
        if (p%x == 0 && q%x == 0) {
            p /= x;
            q /= x;
        }
    }
    cout << p << " " << q << endl;
    
    return 0;
}