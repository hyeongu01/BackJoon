/*
    https://www.acmicpc.net/problem/17219

*/

#include <iostream>
#include <map>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int N, M;
    std::cin >> N >> M;
    std::map<std::string, std::string> note;
    std::string outputs;

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
        outputs += iter->second + "\n";
    }
    std::cout << outputs;
    
    return 0;
}