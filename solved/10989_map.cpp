/*
    https://www.acmicpc.net/problem/10989

    수 정렬하기 3

    map 을 사용하자!
*/

#include <iostream>
#include <map>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    std::map<int, int> m;
    for (int i = 0; i < N; i++) {
        int temp;
        std::cin >> temp;
        if (m.find(temp) == m.end()) { // temp 가 m에 없다면
            m.insert({temp, 1});
        } else {
            m[temp] ++;
        }
    }
    for (auto x: m) {
        for (int i = 0; i < x.second; i++) {
            std::cout << x.first << '\n';
        }
    }
    return 0;
}