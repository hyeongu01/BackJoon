/*
    https://www.acmicpc.net/problem/25314
*/

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n/4; i++) {
        cout << "long ";
    }
    cout << "int" << endl;
    return 0;
}
