/*
    https://www.acmicpc.net/problem/2675
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;

    int R[T];
    string S[T];

    for (int i = 0; i < T; i++) {
        cin >> R[i] >> S[i];
    }
    
    for (int i = 0; i < T; i++) {
        for (auto x: S[i]) {
            for (int j = 0; j < R[i]; j++) {
                cout << x;
            }
        }
        cout << endl;
    }

    return 0;
}