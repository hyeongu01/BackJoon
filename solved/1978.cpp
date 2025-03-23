/*
    https://www.acmicpc.net/problem/1978

    소수 찾기
*/

#include <iostream>

bool isSosu(int number) {
    if (number == 1)
        return false;
    else if (number == 2)
        return true;
    else {
        for (int i = 2; i < number; i++) {
            if (number % i == 0)
                return false;
        }
    }
    return true;
}

int main() {
    int N;
    int count = 0;

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        int number;
        std::cin >> number;
        if (isSosu(number))
            count ++;
    }
    std::cout << count << std::endl;

    return 0;
}