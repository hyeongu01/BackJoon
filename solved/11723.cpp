/*
    https://www.acmicpc.net/problem/11723

    사용자 정의 클래스 사용
*/

#include <iostream>
#include <cstring>

class emptyBox {
private:
    bool data[20];
public:
    emptyBox() {
        for (int i = 0; i < 20; i++)
            data[i] = false;
    }
    
    void add(int x) {
        if (data[x-1] == false)
            data[x-1] = true;
    }

    void remove(int x) {
        if (data[x-1] == true)
            data[x-1] = false;
    }

    bool check(int x) {
        if (data[x-1] == true)
            return true;
        else
            return false;
    }

    void toggle(int x) {
        data[x-1] = !data[x-1];
    }

    void all() {
        for (int i = 0; i < 20; i++)
            data[i] = true;
    }

    void empty() {
        for (int i = 0; i < 20; i++)
            data[i] = false;
    }
    
};

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int M;
    std::cin >> M;
    emptyBox eb;

    for (int i = 0; i < M; i++) {
        char instruction[7];
        std::cin >> instruction;

        if (strcmp(instruction, "all") == 0) {
        eb.all();
        } else if (strcmp(instruction, "empty") == 0) {
        eb.empty();
        } else {
            int x;
            std::cin >> x;

            if (strcmp(instruction, "add") == 0) {
            eb.add(x);
            } else if (strcmp(instruction, "remove") == 0) {
            eb.remove(x);
            } else if (strcmp(instruction, "check") == 0) {
                std::cout <<eb.check(x) << "\n";
            } else if (strcmp(instruction, "toggle") == 0) {
            eb.toggle(x);
            } else
                std::cout << "error" << std::endl;
        }
    }

    return 0;
}