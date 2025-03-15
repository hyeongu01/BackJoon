/*
    https://www.acmicpc.net/problem/10845

    정수를 저장하는 queue를 구현하여라
     - 명령어 리스트
         - push X
         - pop
         - size
         - empty
         - front
         - back

    배열을 통한 구현
     + 추후 연결리스트를 통한 구현 예정

    구현 시 두가지 가정 포인트!
     1. push 시 메모리가 부족한 경우 기존 메모리의 2배씩 늘려 사용한다. 
     2. push 시 이전의 사이즈가 0인경우 메모리를 초기화하여 저장한다.

    잘못한 사항
     - front 와 back의 사용을 착각하여 반대로 사용하였다.
*/

#include <iostream>
#include <cstring>

using namespace std;

class Queue {
private:
    int *data = nullptr;
    int dataSize = 0;
    // 마지막 항목 인덱스를 가르킴
    int frontIdx = -1;
    // 처음 항목의 앞을 가르킴
    int backIdx = -1;
public:
    ~Queue();
    void push(int X);
    int pop();
    int size();
    bool empty();
    int front();
    int back();
};

int main() {
    Queue q;
    int n;
    cin >> n;

    for (; n>0; n --) {
        char inst[6];
        cin >> inst;
        if (strcmp(inst, "push") == 0) {
            int x;
            cin >> x;
            q.push(x);
        } else if (strcmp(inst, "pop") == 0) {
            cout << q.pop() << endl;
        } else if (strcmp(inst, "size") == 0) {
            cout << q.size() << endl;
        } else if (strcmp(inst, "empty") == 0) {
            cout << q.empty() << endl;
        } else if (strcmp(inst, "front") == 0) {
            cout << q.front() << endl;
        } else if (strcmp(inst, "back") == 0) {
            cout << q.back() << endl;
        } else {
            cout << "error" << endl;
        }
    }


    return 0;
}

Queue::~Queue() {
    if (dataSize != 0) {
        delete[] data;
        dataSize = 0;
        frontIdx = -1;
        backIdx = -1;
    }
}

bool Queue::empty() {
    return (frontIdx == backIdx);
}

int Queue::front() {
    return (empty() == 1 ? -1 : data[backIdx+1]);
}

int Queue::back() {
    return (empty() == 1 ? -1 : data[frontIdx]);
}

int Queue::size() {
    return frontIdx - backIdx;
}

void Queue::push(int X) {
    if (size() == 0) {
        if (dataSize != 0) {
            delete[] data;
        }
        data = new int[1];
        dataSize = 1;
        data[0] = X;

        frontIdx = 0;
        backIdx = -1;

    } else if ((frontIdx+1) < dataSize) {
        data[frontIdx + 1] = X;
        frontIdx ++;
    } else {
        int previous_size = this->size();
        int *newData = new int[previous_size*2];
        for (int i = 0; i < previous_size; i++) {
            newData[i] = data[backIdx + i + 1];
        }
        newData[previous_size] = X;
        delete[] data;
        data = newData;
        frontIdx = previous_size;
        backIdx = -1;
        dataSize = previous_size * 2;
    }
}

int Queue::pop() {
    if (empty() == 1) {
        return -1;
    } else {
        backIdx ++;
        return data[backIdx];
    }
}
