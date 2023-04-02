#include <iostream>

int main() {
	int size, output = 0;

	std::cin >> size;

	int* arr = new int[size];

	for (int i = 0; i < size; i++) {
		std::cin >> arr[i];
	}

	for (int i = size - 1; i > 0; i--) {
		if (arr[i] <= arr[i - 1]) {
			output += arr[i - 1] - (arr[i] - 1);
			
			arr[i - 1] = arr[i] - 1;
		}
	}
	
	std::cout << output;

}