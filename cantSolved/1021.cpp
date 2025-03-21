/*
    https://www.acmicpc.net/problem/1021

    vector<int> 자료구조 이용
     - 전제조건
         - 원형 큐에 1~N의 숫자가 들어있음 -> 해당 번호로 초기 인덱스 확인
         - 현재 원소 개수(curSize), 현재 초기 인덱스(curFront)를 활용해 회전을 표현
    
     - 의사코드
    n, m 입력
    
*/

#include <iostream>
#include <vector>

using namespace std;

int searchIndex(vector<int> queue, int idx, int curFront) {
    auto nextTarget = queue.begin() + curFront;
    for (int i = 0; i < queue.size(); i++) {
        if (nextTarget >= queue.end())
            nextTarget = queue.begin();
        
        // cout << *(nextTarget) << endl;
        
        if (*(nextTarget) == idx)
            return i;
        nextTarget ++;
    }
    return -1;
}

class circleQueue {
private:
    vector<int> data;
    int curFront = 0;

public:

    void push(int x) {
        this->data.push_back(x);
    }

    int popFirst() {
        int firstData = *(data.begin() + curFront);
        data.erase(data.begin() + curFront);
        return firstData;
    }

    void rotateLeft() {
        curFront = (curFront+1 >= data.size() ? 0 : curFront+1);
    }

    void rotateRight() {
        curFront = (curFront-1 <= 0 ? data.size() - 1 : curFront-1);
    }

    int searchIdx(int idx) {
        for (int i = 0; i < data.size(); i++) {
            
        }


    }

};

int main() {
    int n, m;
    cin >> n >> m;
    circleQueue q;

    for (int i = 0; i < n; i ++) {
        q.push(i+1);
    }

    int target[m];
    for (int i = 0; i < m; i++) {
        cin >> target[i];
    }

    for (int x: target) {
        
    }




    return 0;
}