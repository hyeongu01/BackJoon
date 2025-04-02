/*
    https://www.acmicpc.net/problem/11021
*/

#include <iostream>

int main() {
    int T;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        int a, b;
        std::cin >> a >> b;
        std::cout << "Case #" << i+1 << ": " << a+b << '\n';
    }

    return 0;
}