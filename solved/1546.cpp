/*
    https://www.acmicpc.net/problem/1546
*/

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int Ms[n];
    int MIdx = 0;
    double M = 0.0;

    // 수 입력
    int scoreSum = 0;
    for (int i = 0; i < n; i ++) {
        cin >> Ms[i];
        scoreSum += Ms[i];

        if (M < Ms[i]) {
            MIdx = i;
            M = Ms[i];
        }
    }
    cout << scoreSum /M / n * 100 << endl;

    return 0;
}