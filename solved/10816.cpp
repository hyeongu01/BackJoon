/*
    https://www.acmicpc.net/problem/10816

    1. 일반 배열을 활용해 항목이 나온 횟수를 카운트했다 -> 시간초과
    2. map을 활용해 입력 시 개수를 한번에 카운트했다 -> 시간초과

    3. 스택 두개를 활용해 입력시에는 그냥 받고, 확인할 때 확인된건 제거하는 기능을 추가해보자!
    4. 이진탐색을 활용해보자!

    mulset 자료구조! -> 시간초과

    unordered_map 사용해보자!
    hashMap 기억하자!
*/

#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;

int main() {
    unordered_map<int, int> umap;
    int n, m, num;
    string inStr;

    cin >> n;
    cin.ignore(1000, '\n');
    getline(cin, inStr);
    istringstream iss(inStr);

    while (iss >> num) {
        if (umap.find(num) == umap.end()) {
            umap.insert({num, 1});
        } else {
            umap[num] ++;
        }
    }

    cin >> m;
    cin.ignore(1000, '\n');
    getline(cin, inStr);
    iss.str(inStr);
    iss.clear();

    while (iss >> num) {
        cout << (umap.find(num) == umap.end() ? 0 : umap[num]) << ' ';
    }
    cout << endl;

    return 0;
}