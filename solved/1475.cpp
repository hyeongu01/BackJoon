/*
    https://www.acmicpc.net/problem/1475
*/

#include <iostream>

using namespace std;

int main() {
    char num[8];
    int counter[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    cin >> num;

    for (auto x: num) {
        if (x == '\0') break;
        
        int x_int = int(x) - int('0');
        if (x_int == 9)
            counter[6] ++;
        else 
            counter[x_int] ++;
    }

    int result = 0;
    
    for (int i =0; i < 9; i ++) {
        if (i == 6) {
            if (result < (counter[i]%2 == 0 ? (counter[i] / 2) : (counter[i]/2 + 1)))
                result  = (counter[i]%2 == 0 ? (counter[i] / 2) : (counter[i]/2 + 1));
        } else {
            if (result < counter[i])
                result = counter[i];
        }
    }
    cout << result << endl;

    return 0;
}