/*
    https://www.acmicpc.net/problem/2562

    문제를 딱 보니 두가지 방법이 떠오른다. 뭐가 더 좋은지 구현해보고 생각해보자.
     1. 1차원 배열로 단순하게 선형 탐색을 하는 방법 O(n)의 시간이 걸릴거라고 생각.
     2. map 자료구조를 활용해 key를 입력받은 값으로 하고, value로 인덱스를 저장해 출력하자.
        map 자료구조는 레드블랙트리를 활용해 값을 정렬한다. 여기서는 삽입을 n번 하고, map의 삽입연산은 O(logN)이다.
        따라서, 이 알고리즘의 시간복잡도는 O(nlog(n))이다

    결론: 간단하게 1차원 배열로 구현하자!
*/

#include <iostream>

using namespace std;

int main() {
    int nums[9];
    for (int i =0; i < 9; i++) {
        cin >> nums[i];
    }

    int max = 0;
    int maxIdx = -1;
    for (int i = 0; i < 9; i ++) {
        if (max < nums[i]) {
            max = nums[i];
            maxIdx = i;
        }
    }
    cout << max << endl;
    cout << maxIdx + 1 << endl;

    return 0;
}