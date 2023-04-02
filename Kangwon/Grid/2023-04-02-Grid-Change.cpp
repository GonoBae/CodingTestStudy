#include <iostream>

int main() {
	int input, output = 0;
	
	std::cin >> input;
	input = 1000 - input;

	output += input / 500;
	input = input % 500;
	output += input / 100;
	input = input % 100;
	output += input / 50;
	input = input % 50;
	output += input / 10;
	input = input % 10;
	output += input / 5;
	input = input % 5;

	output += input;

	std::cout << output;

}