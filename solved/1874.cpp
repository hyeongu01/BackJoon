/*
    https://www.acmicpc.net/problem/1874
*/

#include <iostream>
#include <vector>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;
    std::vector<int> stack;
    std::string result;

    int count = 1;
    for (int i = 0; i < n; i++) {
        if (stack.empty()) {
            stack.push_back(count ++);
            result += "+\n";
        }
        int num;
        std::cin >> num;

        while (stack.back() != num) {
            if (count > n)
                break;
            stack.push_back(count ++);
            result += "+\n";
        }
        if (stack.back() != num)
            break;
        stack.pop_back();
        result += "-\n";
    }
    if (stack.empty()) 
        std::cout << result;
    else
        std::cout << "NO\n";
        
    return 0;
}