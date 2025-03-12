/*
    https://www.acmicpc.net/problem/4153
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<bool> result;

    while (true) {
        vector<int> a;
        for (int i = 0; i < 3; i++) {
            int temp;
            cin >> temp;
            a.push_back(temp);
        }

        // 0 0 0 이면 결과 루프 탈출
        if (a[0] == a[1] && a[1] == a[2] && a[0] == 0)
            break;

        auto it = max_element(a.begin(), a.end());
        int long_side = *it;
        a.erase(it);
        if (a[0] * a[0] + a[1] * a[1] == long_side * long_side)
            result.push_back(true);
        else
            result.push_back(false);
    }

    // 결과 출력
    for (auto x: result) {
        cout << (x ? "right" : "wrong") << endl;
    }

    return 0;
}