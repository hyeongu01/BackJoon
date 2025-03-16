/*
    https://www.acmicpc.net/problem/2753
*/

#include <iostream>

using namespace std;

int main() {
    int year;
    cin >> year;
    
    bool answer;
    if ((year%4 == 0 && year%100 != 0) || (year%400 == 0))
        answer = true;
    else
        answer = false;
    cout << answer << endl;

    return 0;
}