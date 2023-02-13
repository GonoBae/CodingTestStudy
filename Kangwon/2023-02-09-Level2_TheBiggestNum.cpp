#include <string>
#include <vector>
#include <algorithm>

bool mySort(int i, int j);

std::string solution(std::vector<int> numbers) {
    std::string answer = "";
    sort(numbers.begin(), numbers.end(), mySort);

    for (auto& i : numbers) {
        answer += std::to_string(i);
    }

    if (answer.size() != 1 && answer.front() == '0') {
        return "0";
    }

    return answer;
}

bool mySort(int i, int j) {
   return std::stoi(std::to_string(i) + std::to_string(j)) > std::stoi(std::to_string(j) + std::to_string(i));
}

int main() {
    std::vector<int> a = {0,0,0,0};
    solution(a);

    return 0;
}