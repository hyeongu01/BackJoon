/*
    https://www.acmicpc.net/problem/
    
    숫자 범위가 살벌하다.
    N <= 10^(1,000,000)
    높은 자리수부터 20000303을 빼는 작업을 반복하자.

    우선 입력은 string으로 밭는다.

    while (현재 자리수 == 맨 뒤 자리수)
        if (맨 앞 자리수 - 20000303 > 0):
            맨 앞 자리수  -= 20000303;
        else:
            한칸 왼쪽으로 쉬프트

            "201220303002"

201220303002
20000303
00121727

001217273002
-20000303
-~

001217273002
--20000303
-~

001217273002
---
*/

#include <iostream>
#include <string>
#define birth 20000303

using namespace std;

int main() {
    string n = "201220303002";
    // cin >> n;
    int current_pos = 8;

    while (true) {
        if (current_pos == n.length()) {
            break;
        }
        cout << stoi(n.substr(0, current_pos)) << endl;
        int div = stoi(n.substr(0, current_pos-1)) - birth;
        if (div >= 0) {
            n.replace(current_pos, 8, to_string(div));
            cout << n << endl;
        } else {
            current_pos ++;
        }
    }


    return 0;
}