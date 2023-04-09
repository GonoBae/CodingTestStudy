#include<iostream>
#include<vector>

int main() {
	int a;
	std::cin >> a;

	for (int i = 0; i < a; i++) {
		int b, max = 0;
		long long result = 0;
		std::vector<int> vec;
		std::cin >> b;
		
		for (int j = 0; j < b; j++) {
			int tmp;
			std::cin >> tmp;
			vec.push_back(tmp);
		}

		for (int j = b - 1; j >= 0; j--) {
			if (max < vec[j]) {
				max = vec[j];
			}
			else {
				result += max - vec[j];
			}
		}

		std::cout << result << std::endl;
	}

	return 0;
}