/*
    https://www.acmicpc.net/problem/15829

    Hashing에 대한 내용

    첫번째 시도: 50점 (문자열 길이 1 <= L <= 5)
    나머지 50점을 맞으려면 문자열길이 50개까지 연산 가능해야한다.
    이 때 제곱연산이 int 형을 초과하여 문제가 생긴듯 하다.

    거듭제곱 계산 시 r을 곱할 때마다 M의 나머지로 치환하여 수가 너무 커지는것을 막음
*/
#include <iostream>
#define M 1234567891
#define r 31

using namespace std;

int cal_hash(char* c, int l) {
    int i = 0;
    unsigned long long sum_a = 0;
    while(c[i] != '\0') {
        unsigned long long a = (int)c[i] - (int)'a' + 1;
        for (int j = 0; j < i; j++) {
            a = a * r;
            a = a % M;
        }
        sum_a += a;
        i++;
    }
    return sum_a%M;
}

int main() {
    int l;
    cin >> l;

    char c[l+1];
    cin >> c;

    cout << cal_hash(c, l) << endl;;

    return 0;
}