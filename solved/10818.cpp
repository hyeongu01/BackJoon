/*
    https://www.acmicpc.net/problem/10818

    set
    rbegin() 함수는 마지막 항목에 접근 가능하다.

    + iterator 라이브러리의 std::advacnce(it, 3)을 활용해 특정 인덱스에 접근 가능한다.

    * set자료구조를 사용하니 시간초과가 생겼다. max_element가 더 효율적인듯?

    내 생각: set<int> 의 삽입, 삭제, 검색의 시간복잡도는 log(N)이고, 해당 코드에서는 N번의 삽입이 이루어지므로 코드의 시간복잡도는 O(NlogN)이다.
           vector<int> 에서 max_element(), min_element() 의 시간복잡도는 N이다. 최대값, 최소값을 찾으므로 해당 코드의 시간복잡도는 2N, 빅오 표기법으로 O(N)이다.
           그러므로 O(NlogN)보다는 O(N)이 효율이 좋다고 생각한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> numbers;

    for (int i = 0; i < N; i++) {
        int number;
        cin >> number;
        numbers.push_back(number);
    }

    cout << *min_element(numbers.begin(), numbers.end()) << " " << *max_element(numbers.begin(), numbers.end()) << endl;

    return 0;
}