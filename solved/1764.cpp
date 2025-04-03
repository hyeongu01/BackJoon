/*
    https://www.acmicpc.net/problem/1764

*/

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int N, M;
    std::cin >> N >> M;
    std::set<std::string> cantHear;
    std::vector<std::string> result;
    

    for (int i = 0; i < N; i++) {
        std::string tempName;
        std::cin >> tempName;

        cantHear.insert(tempName);
    }

    for (int i = 0; i < M; i ++) {
        std::string tempName;
        std::cin >> tempName;

        if (cantHear.find(tempName) != cantHear.end()) {
            cantHear.erase(tempName);
            result.push_back(tempName);
        }
    }
    std::sort(result.begin(), result.end());

    std::cout << result.size() << "\n";
    for (auto x: result) {
        std::cout << x << "\n";
    }

    return 0;
}