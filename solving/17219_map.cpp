/*
    https://www.acmicpc.net/problem/17219

*/

#include <iostream>
#include <map>

int main() {
    int N, M;
    std::cin >> N >> M;
    std::map<std::string, std::string> note;

    for (int i = 0; i < N; i++) {
        std::string site;
        std::string pass;
        std::cin >> site >> pass;

        note.insert({site, pass});
    }

    for (int i = 0; i < M; i++) {
        std::string site;
        std::cin >> site;
        auto iter = note.find(site);
        std::cout << iter->second << "\n";
    }
    

    return 0;
}