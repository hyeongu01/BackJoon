/*
    https://www.acmicpc.net/problem/10699
    
    오늘 날짜 출력하는 프로그램을 작성하시오.
*/

#include <iostream>
#include <ctime>
#include <string>
#include <map>

using namespace std;

int main() {
    map<string, string> monthTInt = {
        {"Jan", "01"},
        {"Feb", "02"},
        {"Mar", "03"},
        {"Apr", "04"},
        {"May", "05"},
        {"Jun", "06"},
        {"Jul", "07"},
        {"Aug", "08"},
        {"Sep", "09"},
        {"Oct", "10"},
        {"Nov", "11"},
        {"Dec", "12"}
    };

    time_t now = time(nullptr) + 9*3600;
    string cur_time = ctime(&now);

    string year = cur_time.substr(20, 4);
    string month = monthTInt[cur_time.substr(4, 3)];
    string day = cur_time.substr(8, 2);
    
    cout << year << "-" << month << "-" << day << endl;
    return 0;
}