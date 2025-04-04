/*
    https://www.acmicpc.net/problem/2606

*/

#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <vector>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int N;
    int M;
    std::queue<int> infectingQueue;
    std::set<int> safeSet;
    std::map<int, std::vector<int>> connectionMap;
    // std::vector<int> infectedVector;
    int infectedComp = 0; // 감염된 컴퓨터 수 카운트

    std::cin >> N;
    std::cin >> M;
    
    // 연결관계 저장
    for (int i = 0; i < M; i++) {
        int x, y;
        std::cin >> x >> y;

        if (connectionMap.find(x) == connectionMap.end()) {
            connectionMap.insert({x, {y}});
        } else {
            connectionMap.find(x)->second.push_back(y);
        }

        if (connectionMap.find(y) == connectionMap.end()) {
            connectionMap.insert({y, {x}});
        } else {
            connectionMap.find(y)->second.push_back(x);
        }
    }

    // infectingQueue에 1 삽입 (초기 감염 컴퓨터)
    infectingQueue.push(1);
    
    // safeSet에 2 ~ N 삽입
    for (int i = 2; i <= N; i++) {
        safeSet.insert(i);
    }

    while (infectingQueue.empty() != true) {
        int currentComp = infectingQueue.front();
        infectingQueue.pop();
        if (connectionMap.find(currentComp) != connectionMap.end()) {
            std::vector<int> connections = connectionMap.find(currentComp)->second;
            connectionMap.erase(currentComp);
            for (auto x: connections) {
                if (safeSet.find(x) != safeSet.end()) {
                    infectingQueue.push(x);
                    safeSet.erase(x);
                }
            }
        }

        // 감염된 컴퓨터 벡터에 현재 컴퓨터 삽입
        // infectedVector.push_back(currentComp);
        infectedComp ++;
    }

    // 1번 컴퓨터는 제외하기 때문에 -1
    std::cout << infectedComp-1 << "\n";

    // for (int x: infectedVector) {
    //     std::cout << x << " ";
    // }
    // std::cout << std::endl;

    return 0;
}