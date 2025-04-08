/*
    https://www.acmicpc.net/problem/9012
*/

#include <iostream>
#include <vector>
#include <string>

bool checkPars(std::string inputPars) {
    std::vector<char> pars;

    while (inputPars.empty() != true) {
        char temp = inputPars.back();
        inputPars.pop_back();
        if (temp == ')') {
            pars.push_back(temp);
        } else {
            if (pars.empty() == false && pars.back() == ')') {
                pars.pop_back();
            }
            else
                return false;
        }
    }
    if (pars.empty() == true)
        return true;
    else
        return false;
}

int main() {
    int T;
    std::cin >> T;
    std::string result;

    for (int i = 0; i < T; i++) {
        std::string inputPars;
        std::cin >> inputPars;
        result += (checkPars(inputPars) ? "YES\n" : "NO\n");
    }
    std::cout << result;

    return 0;
}