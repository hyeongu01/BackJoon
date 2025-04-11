/*
    https://www.acmicpc.net/problem/11659
*/

#include <iostream>
#include <sstream>
#include <string>

int sumBetween(int *nums, int a, const int& b) {
    int sum = nums[b-1] - (a==1 ? 0 : nums[a-2]);
    return sum;
}

void getNums(int *list) {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);

    int num;
    int i = 0;
    while (iss >> num) {
        list[i++] = num + list[i-1];
    }
}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int N, M;
    std::cin >> N >> M;
    std::cin.ignore(10, '\n');

    int list[N];
    getNums(list);

    for (int i = 0; i < M; i++){
        int a, b;
        std::cin >> a >> b;
        std::cout << sumBetween(list, a, b) << "\n";
    }

    return 0;
}
