/*
    https://www.acmicpc.net/problem/1181

    단어 정렬
     - 길이순으로
     - 같다면 사전순으로
*/

#include <iostream>
#include <map>
#include <algorithm>
#include <string>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    int N;
    std::cin >> N;

    std::multimap<int, std::string> uM;
    std::vector<std::string> vector;
    std::vector<std::string> tempVector;
    for (int i =0; i < N; i++) {
        std::string str;
        std::cin >> str;
        uM.insert({str.length(), str});
    }

    // key가 같다면 tempVector으로 넣어 정렬 후 삽입
    while (uM.empty() != true) {
        if (uM.size() == 1) {
            auto iter = uM.begin();
            if (tempVector.empty()) {
                vector.push_back(iter->second);
                break;
            } else {
                tempVector.push_back(iter->second);
                std::sort(tempVector.begin(), tempVector.end());
                while (tempVector.empty() != true) {
                    if (vector.empty()) {
                        vector.push_back(tempVector.back());
                    } else {
                        if (vector.back() != tempVector.back())
                            vector.push_back(tempVector.back());
                    }
                    tempVector.pop_back();
                }
                break;
            }
            
        } else {
            auto iter = uM.end();
            iter --;
            auto prevIter = iter;
            prevIter --;
            if (iter->first != prevIter->first) {
                if (tempVector.empty()) {
                    vector.push_back(iter->second);
                    uM.erase(iter);
                } else {
                    tempVector.push_back(iter->second);
                    uM.erase(iter);
                    std::sort(tempVector.begin(), tempVector.end());
                    while (tempVector.empty() != true) {
                        if (vector.empty()) {
                            vector.push_back(tempVector.back());
                        } else {
                            if (vector.back() != tempVector.back())
                                vector.push_back(tempVector.back());
                        }
                        tempVector.pop_back();
                    }
                }
            } else {
                tempVector.push_back(iter->second);
                uM.erase(iter);
            }
        }
    }

    // 결과 출력
    while (vector.empty() != true) {
        std::cout << vector.back() << "\n";
        vector.pop_back();
    }

    return 0;
}