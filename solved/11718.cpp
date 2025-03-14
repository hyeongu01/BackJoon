/*
    https://www.acmicpc.net/problem/11718

    100자를 넘지 않는다 -> 101크기의 문자열 사용해라!
*/

#include <iostream>

using namespace std;

int main() {
    char input[101];
    for (int i = 0; i < 100; i++) {
        cin.getline(input, 101);
        cout << input << endl;
    }
    return 0;
}
