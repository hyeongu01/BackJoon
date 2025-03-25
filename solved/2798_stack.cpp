/*
    https://www.acmicpc.net/problem/2798

    # 의사코드
    정답을 저장할 변수 result 선언 초기값은 0
    카드 번호를 저장할 스택 s 선언 후 카드를 순서대로 삽입
    이전에 뽑은 카드번호를 저장할 변수 preNum 선언
    preNum = s.pop() // s의 맨 위 원소 preNum 에 저장 후 pop
    계산된 카드번호를 저장할 tempS 선언

    while (s.size() >= 2) {
        while (s.size() >= 2) {
            tempS.push(s.pop());
            for (auto x: s) {
                int tempResult = tempS.back() + x + preNum
                if (tempResult <= M && M-tempResul < M-result) {
                    result = tempResult;
                }
            }
        }
        while (tempS.empty() != true) {
            s.push(tmepS.pop())
        }
        preNum = s.pop()
    }

    결과: result.
*/

#include <iostream>
#include <vector>

int main() {
    int N, M;
    std::vector<int> s;
    std::cin >> N >> M;
    int result = 0;
    
    // 입력 카드번호 스택에 저장
    for (int i = 0; i < N; i++) {
        int temp;
        std::cin >> temp;
        s.push_back(temp);
    }

    // preNum 초기값 설정 및 임시 스택 생성
    int preNum = s.back();
    s.pop_back();
    std::vector<int> tempS;

    // s의 원소가 2개 미만이 될때까지 반복
    while (s.size() >= 2) {
        // s의 원소가 2개 미만이 될때까지 반복
        while (s.size() >= 2) {
            tempS.push_back(s.back());
            s.pop_back();
            for (auto x: s) {
                int tempResult = tempS.back() + x + preNum;
                if (tempResult <= M && M-tempResult < M-result)
                    result = tempResult;
            }
        }
        while (tempS.empty() != true) {
            s.push_back(tempS.back());
            tempS.pop_back();
        }
        preNum = s.back();
        s.pop_back();
    }
    std::cout << result << std::endl;

    return 0;
}