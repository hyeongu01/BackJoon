/*
    https://www.acmicpc.net/problem/1010

    콤비네이션을 구하는 문제!

    팩토리얼 연산 시 그냥 곱해서 나눌 시 int 형의 범위를 초과하는 현상 발견하여 나눌 수 있을 때 나누는 방법을 사용하였다.
*/

#include <iostream>

using namespace std;

int min(int a, int b) {
    return (a > b ? b : a);
}

int main() {
    int t;
    cin >> t;
    for (; t>0; t --) {
        int N, M;
        cin >> N >> M;
        
        int r = min(N, M-N);
        int sonPart = 1;
        int parentPart = 1;
        for (int i = 0; i < r; i ++) {
            sonPart *= M-i;
            if (sonPart % (i+1) == 0) {
                sonPart /= (i+1);
            } else 
                parentPart *= i+1;
            // cout << sonPart << " / " << parentPart << endl;
        }
        cout << sonPart/parentPart << endl;
    }

    return 0;
}