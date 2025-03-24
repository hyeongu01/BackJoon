/*
    https://www.acmicpc.net/problem/2751

    std::sort()를 활용한 수 정렬
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    int N;
    std::vector<int> nums;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        std::cin >> num;
        nums.push_back(num);
    }

    std::sort(nums.begin(), nums.end());
    for (int x: nums) {
        std::cout << x << "\n";
    }

    return 0;
}
