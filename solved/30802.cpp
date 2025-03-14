/*
    https://www.acmicpc.net/problem/30802

*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void print_cal_pencle(int N, int P) {
    cout << N/P << " " << N%P << endl;
}

int cal_shirt(vector<int> sizes, int T) {
    int sum = 0;
    for (auto size: sizes) {
        sum += (size == 0 ? 0 : ((size-1) / (T)) + 1);
    }
    return sum;
}

int main() {
    int N;
    cin >> N;
    cin.ignore(15, '\n');

    vector<int> sizes;
    for (int i = 0; i < 6; i++) {
        int temp;
        cin >> temp;
        sizes.push_back(temp);
    }

    int t;
    int p;
    cin >> t >> p;

    cout << cal_shirt(sizes, t) << endl;
    print_cal_pencle(N, p);

    return 0;
}