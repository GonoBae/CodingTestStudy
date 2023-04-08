#include <iostream>
#include <vector>

int main() {
	int a;
	std::cin >> a;

	for (int i = 0; i < a; i++) {
		int num;
		std::cin >> num;

		std::vector<int> vec;
		for (int i = 0; i < num; i++) {
			int tmp;
			std::cin >> tmp;
			vec.push_back(tmp);
		}

		int cnt = 0, result = 0;
		
		for (int i = 0; i < num - 1; i++) {
			if (vec[i] <= vec[i + 1]) {
				cnt++;
				result += (vec[i + 1] - vec[i]) * cnt;
			}
			else {
				cnt = 0;
			}
		}
		std::cout << result <<std::endl;
	}
}