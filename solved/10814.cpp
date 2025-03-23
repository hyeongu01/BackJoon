/*
    https://www.acmicpc.net/problem/10814

    나이순 정렬, 같다면 순서를 그대로
     -> map 자료구조를 활용 
        map 은 레드블랙트리 자료구조를 활용하여 key값을 기준으로 자동 정렬하여 삽입, 삭제한다.
        기본적으로 map은 key값의 중복을 허용하지 않지만, multimap은 허용한다.

    아래 두 코드를 추가하니 실행시간이 2756ms -> 60ms가 되었다.
     std::cin.tie(NULL);
     std::ios_base::sync_with_stdio(false);
*/

// Multimap을 활용한 풀이
#include <iostream>
#include <map>
#include <string>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::multimap<int, std::string> users;

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        int age;
        std::string name;
        std::cin >> age >> name;

        users.insert({age, name});
    }

    for (auto x: users) {
        std::cout << x.first << " " << x.second << "\n";
    }

    return 0;
}


// 결과: 시간초과
/*
#include <iostream>
#include <vector>
#include <string>

template<typename T1, typename T2>
class dic 
{
private:
    T1 val1;
    T2 val2;
public:
    dic(T1 v1, T2 v2) {
        this->val1 = v1;
        this->val2 = v2;
    }
    T1 first() {
        return val1;
    }
    T2 second() {
        return val2;
    }
};

int main() {
    int N;
    std::vector<dic<int, std::string>> users;
    
    // 문제 입력
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        int age;
        std::string name;
        std::cin >> age >> name;

        users.push_back({age, name});
    }

    // 정렬
    for (int i = N-1; i >= 0; i--) {
        if (i == 0) {
            users.push_back(users[0]);
            users.erase(users.begin());
        } else {
            // 최소값 찾기
            int min = users[0].first();
            int minIdx = 0;
            for (int j = 1; j <= i; j++) {
                if (min > users[j].first()) {
                    min = users[j].first();
                    minIdx = j;
                }
            }

            // 찾은 최소값 추출 후 맨 뒤에 삽입
            users.push_back(users[minIdx]);
            users.erase(users.begin() + minIdx);
        }
    }

    for (auto x: users) {
        std::cout << x.first() << ' ' << x.second() << std::endl;
    }

    return 0;
}
*/