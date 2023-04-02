#include <iostream>
#include <vector>
#include <algorithm>
bool compare(std::pair<int, int>, std::pair<int, int>);

int main() {
    int num, output = 0;

    std::vector<std::pair<int, int>> CT;
    std::cin >> num;

    for (int i = 0; i < num; i++) {
        int a, b;
        std::cin >> a >> b;
        CT.push_back(std::make_pair(a, b));
    }
    std::sort(CT.begin(), CT.end(), compare);
    int tmp_end = 0;
    for (int i = 0; i < num; i++) {
        if (tmp_end <= CT[i].first) {
            tmp_end = CT[i].second;
            output++; 
        }
    }

    std::cout << output;
    return 0;
}

bool compare(std::pair<int, int> p1, std::pair<int, int>p2) {

    if (p1.second == p2.second) {
        return p1.first < p2.first;
    }
    return p1.second < p2.second;
}

