#include <iostream>
#include <algorithm>

int main() {
	int x, y;
	std::cin >> x >> y;

	if (x == 1) {
		std::cout << 1;
	}
	else if (x == 2) {
		//첫번째 칸은무조건 들어가니까 
		std::cout << std::min(4, (y + 1) / 2);
	}
	else {
		if (y <= 6) {
			std::cout << std::min(4, y);
		}
		else {
			std::cout << y - 2;
		}
	}

	return 0;
}
