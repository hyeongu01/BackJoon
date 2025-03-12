/*
    https://www.acmicpc.net/problem/31403

    A, B, C가 주어질 때
    1. A, B, C를 숫자로 보고 A+B-C
    2. A, B, C를 문자열로 보고 A+B-c

    (문자열에서 +는 이어붙이는것이고, -는 숫자로서 빼는것이다.)
*/  

#include <iostream>
#include <string>

using namespace std;

int main() {
    string a;
    string b;
    string c;
    cin >> a >> b >> c;

    cout << stoi(a) + stoi(b)- stoi(c) << endl;
    cout << stoi(a+b) - stoi(c) << endl;
}