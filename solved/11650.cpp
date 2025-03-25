/*
    https://www.acmicpc.net/problem/11650

    좌표를 하나의 수로 표현하여 정렬하자!
    - 입력된 값에 100,000을 더해서 좌표의 범위를 0에서 200,000으로 만든다.
    - x좌표와 y좌표를 이어붙여서 하나의 큰 수를 만든다
        - ex) x: 5, y: -20 → 100005 099980 (편의를 위해 x에 해당하는 부분과 y에 해당하는 부분을 공백으로 나누었다. 실제로는 두 수를 이어붙여서 하나의 큰 수를 만든다.)
        - ex) x: -90,000, y: 100,000 → 010000 200000
    - 이 수를 기분으로 정렬하여 출력할 때에는 반대의 과정을 거친다.

    위 방식의 주의사항이 있다면, 합쳐진 수의 범위는 0에서 200,000,200,000이기 때문에 int 형보다 범위가 큰 long long 타입의 변수를 사용해야 한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

long long toLong(long long x, int y) {
    long long newX = (x+100000) * 1000000;
    long long newY = y+100000;
    return newX+newY;
}

void printLong(long long point) {
    int x = point / 1000000;
    int y = point % 1000000;
    std::cout << x - 100000 << ' ' << y - 100000 << "\n";
}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::vector<long long> points;

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        long long x;
        int y;
        std::cin >> x >> y;
        long long temp = toLong(x, y);

        points.push_back(toLong(x, y));
    }
    std::sort(points.begin(), points.end());

    for (auto x: points) {
        printLong(x);
    }

    return 0;
}