/*
    https://www.acmicpc.net/problem/30802

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print_cal_pencle(int N, int P) {
    cout << N/P << " " << N%P << endl;
}

int cal_shirt(vector<int> sizes, int T) {
    int sum = 0;
    for (auto size: sizes) {
        sum += ((size-1) / T) + 1;
    }
    return sum;
}

int main() {
    int N;
    cin >> N;
    cin.ignore(10, '\n');

    string sizes;
    getline(cin, sizes);

    cout << sizes << endl;
    

    


    return 0;
}