/*
    https://www.acmicpc.net/problem/10828

    스택을 구현한 다음 다음 입력으로 주어지는 명령을 처리하는 프로그램 작성
     - push X: 정수 X를 스택에 넣는 연산
     - pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택이 비었을 경우 -1을 출력한다.
     - size: 스택에 들어있는 정수의 개수를 출력한다.
     - empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
     - top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다. 
*/

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

template<typename T>
class Stack {
public:
    // Stack();
    ~Stack();
    void push(T x);
    void pop();
    void size();
    void empty();
    void top();

private:
    T *data = nullptr;
    size_t data_size = 0;
};

int main() {
    Stack<int> s;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char inst[6];
        cin >> inst;

        if (strcmp(inst, "push") == 0) {
            int x;
            cin >> x;
            cin.ignore(13, '\n');
            s.push(x);
        } else if (strcmp(inst, "pop") == 0) {
            s.pop();
        } else if (strcmp(inst, "size") == 0) {
            s.size();
        } else if (strcmp(inst, "empty") == 0) {
            s.empty();
        } else if (strcmp(inst, "top") == 0) {
            s.top();
        } else {
            cout << "error" << endl;
        }
    }
    return 0;
}


template<typename T>
Stack<T>::~Stack() {
    if (data_size != 0) {
        delete[] data;
        data_size = 0;
    }
}

template<typename T>
void Stack<T>::push(T x) {
    if (data_size == 0) {
        data = new T[1];
        data[0] = x;
        data_size = 1;
    } else {
        T temp[data_size];
        for (int i = 0; i < data_size; i++) {
            temp[i] = data[i];
        }

        delete[] data;
        data = new T[data_size + 1];
        for (int i = 0; i < data_size; i++) {
            data[i] = temp[i];
        }
        data[data_size++] = x;
    }
}

template<typename T>
void Stack<T>::pop() {
    if (data_size == 0) {
        cout << -1 << endl;
    } else if (data_size == 1) {
        cout << data[0] << endl;
        delete[] data;
        data_size--;
    } else {
        cout << data[data_size - 1] << endl;
        data_size --;
        T *newData = new T[data_size];
        for (int i = 0; i < data_size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
}

template<typename T>
void Stack<T>::size() {
    cout << data_size << endl;
}

template<typename T>
void Stack<T>::empty() {
    cout << (data_size == 0 ? 1 : 0)<< endl;
}

template<typename T>
void Stack<T>::top() {
    cout << (data_size == 0 ? -1 : data[data_size-1]) << endl;
}
