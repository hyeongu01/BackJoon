/*
    https://www.acmicpc.net/problem/28701
*/

#include <iostream>

int main() {
    int N;
    std::cin >> N;
    int first = 0;
    int third = 0;

    for (int i = 1; i <= N; i ++) {
        first += i;
        third += i * i * i;
    }
    std::cout << first << '\n' << first * first << '\n' << third << '\n';

    return 0;
}