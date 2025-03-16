/*
    https://www.acmicpc.net/problem/2164

    남은 카드 계산

    1. 배열로 0번인덱스에 맨 위, n-1번 인덱스에 맨 아래 숫자를 담는다. (배열의 크기는 N*2이다.)
    2. top, bottom 변수가 맨위, 아래 인덱스를 저장.
*/

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int top = 0;
    int bottom = n-1;

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    int cards[n*2];
    for (int i = 0; i < n*2; i++) {
        cards[i] = i + 1;
    }
    int finalNumber = 0;

    while (true) {
        top ++;
        if (bottom == top) {
            finalNumber = cards[bottom];
            break;
        }
        cards[++ bottom] = cards[top ++];
    }
    cout << finalNumber << endl;

    return 0;
}