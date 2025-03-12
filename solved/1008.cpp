/* 
    https://www.acmicpc.net/problem/1008

    A, B를 입렵받은 후 A/B를 출력하는 프로그램

    cout.precision()를 통해 소수점 출력 범위 설정 하능
    이는 정수쪽도 포하이기 때문에 cout << fixed;를 하여 소수점만을 설정한다.
    (되돌리려면 cout.unsetf(ios::fixed)를 하여 되돌린다.)
*/

#include <iostream>

using namespace std;

int main() {
    int a;
    double b;

    cin >> a >> b;
    // cout << fixed; 
    cout.precision(10);
    // cout.unsetf(ios::fixed);
    cout << fixed<< a/b << endl;
    return 0;
}