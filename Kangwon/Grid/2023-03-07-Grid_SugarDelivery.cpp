#include <iostream>
#include <vector>
int solution(int num);

int main() {

    int num;
    std::cin >> num;
    std::cout << solution(num);

    return 0;
}

int solution(int num) {
    // "5로 최대한 많이 갖고가야 됨"

    for (int i = num / 5; i >= 0; i--) {        
        int j = num - (5 * i);
        if (j % 3 == 0) {
            return (j / 3) + i;
        }
    }
    return -1;
}
