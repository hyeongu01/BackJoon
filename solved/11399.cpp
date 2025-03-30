/*
    https://www.acmicpc.net/problem/11399
*/

#include <iostream>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    int ps[N];
    int result = 0;
    

    for (int i = 0; i < N; i++) {
        std::cin >> ps[i];
    }
    std::sort(ps, ps+N);

    for (int i = 0; i < N; i++) {
        result += ps[i] * (N-i);
    }
    std::cout << result << "\n";

    return 0;
}