/*
    https://www.acmicpc.net/problem/1920
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    std::vector<int> vec;
    std::string inputs;
    std::string outputs;
    int N, M;

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        std::cin >> num;

        vec.push_back(num);
    }
    std::sort(vec.begin(), vec.end());

    std::cin >> M;
    for (int i = 0; i < M; i++) {
        int num;
        std::cin >> num;
        outputs += (std::binary_search(vec.begin(), vec.end(), num) ? "1\n" : "0\n");
    }
    std::cout << outputs;

    return 0;
}