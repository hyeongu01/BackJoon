/*
    https://www.acmicpc.net/problem/2609
    
    Topic: 최대공약수와 최소공배수

     - N, M의 최대공약수: N보다 작은 수 중 가장 큰 약수
     - N, M의 최대 공배수: N과 M의 배수 중 가장 작은 배수

    무식한 방법
        1. 최대공약수
            min(N, M)에서 1씩 뺴가면서 N과 M의 나머지가 0인 수를 출력
        2. 최소공배수
            N에서 1 ... M 해가면서 M으로 나눴을 때 나머지가 0인 수를 출력
    
    // 좀 더 머리 쓴 방법
    //     N의 약수를 모두 구한다. -> dN에 저장
    //     M의 약수를 모두 구한다. -> dM에 저장

    //     1. 최대공약수
    //         겹치는 약수를 찾아 dN, dM에서 추출하여 가져온다.
    //         겹치는 약수를 모두 곱한다
    //     2. 최소공배수
    //         최대공약수 * dN, dM의 남은 약수들
*/

// 무식한 방법
#include <iostream>

int main() {
    int N, M;
    std::cin >> N >> M;

    // maxCD = min(N, M), 같으면 N
    int maxCD = (N <= M ? N : M);
    for (; maxCD > 0; maxCD--) {
        if (N%maxCD == 0 && M%maxCD == 0) {
            std::cout << maxCD << "\n";
            break;
        }
    }

    // 초기값 N, N씩 더해가며 M으로 나눴을 때 나머지가 0인 수를 출력
    for (int i = 1; i <= M; i++) {
        int minCM = N*i;
        if (minCM % M == 0) {
            std::cout << minCM << "\n";
            break;
        }
    }

    return 0;
}