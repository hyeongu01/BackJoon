/*
    https://www.acmicpc.net/problem/1259
*/

#include <iostream>
#include <string>

bool is_palind(std::string s) {
    std::string s1(s);
    std::string s2;

    while (s.empty() == false) {
        s2.push_back(s.back());
        s.pop_back();
    }

    return (s1 == s2 ? true : false);
}

int main() {
    while (true) {
        std::string s;
        std::cin >> s;
        if (s == "0")
            break;
        else {
            std::cout << (is_palind(s) ? "yes\n" : "no\n");
        }
    }
    return 0;
}