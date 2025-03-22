#include <iostream>
#include <vector>
#include <memory>

using namespace std;

int main() {
    vector<int> vec1 = {1, 2, 3};
    vector<int> vec2;
    shared_ptr<vector<int>> ptr = make_shared<vector<int>>(vec1);

    cout << (*ptr)[0] << endl;

    return 0;
}