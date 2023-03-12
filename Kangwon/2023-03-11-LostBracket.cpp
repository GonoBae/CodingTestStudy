#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int solution(std::string str);
std::vector<std::string> split(std::string str, char Delimiter);

int main() {
    std::string str;
    std::cin >> str;
    std::cout << solution(str);

    return 0;
}

int solution(std::string str) {
    bool minus = str[0] != '-';
    // - 연산이 나오기 전까지 전부 먼저 계산해준다
    int sum = 0;
    std::vector<std::string> tmp = split(str,'-');

    for (int i = 0; i < tmp.size();i++) {
        int sum2 = 0;
        std::vector<std::string> tmp2 = split(tmp[i], '+');
    
        for (int j = 0; j < tmp2.size(); j++) {
            sum2 += stoi(tmp2[j]);
        } 

        if (i == 0) {
            if (minus) sum2 *= -1;
        }
        sum -= sum2;
    }

    return sum;
}

std::vector<std::string> split(std::string str, char Delimiter) {
    std::istringstream iss(str);
    std::string buffer;

    std::vector<std::string> result;

    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);
    }

    return result;
}