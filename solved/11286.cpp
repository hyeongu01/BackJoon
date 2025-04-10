/*
    https://www.acmicpc.net/problem/11286

    
*/

#include <iostream>
#include <set>

void push(std::multiset<int>& absHeap, int item) {
    absHeap.insert(item);
}

int pop(std::multiset<int>& absHeap) {
    if (absHeap.empty() == true)
        return 0;

    int result;
    auto iter = absHeap.upper_bound(0);

    result = *iter;
    if (iter == absHeap.end()) {
        iter --;
    } else if (iter != absHeap.begin()) {
        iter --;
        if (result < -(*iter)) {
            iter ++;
        }
    }

    result = *iter;
    absHeap.erase(iter);
    return result;
}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    int N;
    std::multiset<int> absHeap;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        std::cin >> x;
        if (x == 0) {
            std::cout << pop(absHeap) << "\n";
        } else {
            push(absHeap, x);
        }
    }

    return 0;
}