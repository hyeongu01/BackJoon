/*
    https://www.acmicpc.net/problem/27959
*/

#include <iostream>

int main() {
    int N, M;
    std::cin >> N >> M;
    std::cout << (N*100 >= M ? "Yes" : "No") << '\n';
    return 0;
}