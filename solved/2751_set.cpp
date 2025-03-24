/*
    https://www.acmicpc.net/problem/2751
    
    수 정렬하기

     - 제약 조건
        N: 1 <= N <= 1,000,000
        주어지는 수 num: |num| <= 1,000,000
     - N, num은 int 형으로 하면 충분할 것 같다.
    
    자동정렬되는 set 자료구조를 활용하면 될것같다!
*/

#include <iostream>
#include <set>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::set<int> nums;

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        std::cin >> temp;
        nums.insert(temp);
    }

    for (int x: nums) {
        std::cout << x << "\n";
    }
    std::cout << "\n";

    return 0;
}

