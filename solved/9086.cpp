/*
    https://www.acmicpc.net/problem/9086
*/

#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    char result[n][2];
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;

        result[i][0] = s[0];
        result[i][1] = s[s.length()-1];
    }

    for (auto x: result) {
        std::cout << x[0] << x[1] << "\n";
    }

    return 0;
}