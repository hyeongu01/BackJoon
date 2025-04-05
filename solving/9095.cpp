/*
    https://www.acmicpc.net/problem/9095
*/
#include <iostream>

int combination(const int& n, int r) {
    int parent = 1;
    int child = 1;
    if (r == 0 || r == n)
        return 1;

    // r, n-r중 작은걸 r에 저장
    r = (r > n-r ? n-r : r);
    
    for (int i = 0; i < r; i++) {
        parent *= n-i;
    }
    for (int i = 0; i < r; i++) {
        child *= r-i;
    }
    return parent/child;
}

int countAdd(int n) {
    int result = 0;

    // 3을 하나씩 늘려가면서 진행
    for (int three = 0; three < 4; three++) {
        if (three * 3 > n)
            break;
        // 2를 하나씩 늘려가면서 진행
        for (int two = 0; two < 6; two++) {
            // 1의 개수는 뺀 수만큼 있다고 하자.
            int one = n - (three * 3 + two * 2);
            if (one >= 0) {
                result += (combination(one+two+three, one) * combination(two+three, two));
                std::cout << "one: " << one << " two: " << two << " three: " << three << std::endl;
                std::cout << "comp: " << (combination(one+two+three, one) * combination(two+three, two)) << " result: " << result << std::endl;
            } else
                break;
        }
    }
    return result;
}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;

    for (int i = 0; i < T; i++) {
        int n;
        std::cin >> n;
        std::cout << countAdd(n) << "\n";
    }

    return 0;
}