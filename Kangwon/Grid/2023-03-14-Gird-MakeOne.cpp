#include <iostream>
#include <vector>
//

int main() {
	int input = 0;
	std::cin >> input;
	int bp[1000001] = { 0, };

	for (int i = 0; i <= input; i++) {
		if (i == 0 || i == 1) {
			bp[i] = 0;
		}
		else {
			if (i % 3 == 0) {
				bp[i] = std::min(bp[i / 3], bp[i - 1]) + 1;
			}
			else if (i % 2 == 0) {
				bp[i] = std::min(bp[i / 2], bp[i - 1]) + 1;
			}
			else {
				bp[i] = bp[i - 1] + 1;
			}
		}
	}

	std::cout << bp[input];

	return 0;
}
//왜 틀렸지..?
