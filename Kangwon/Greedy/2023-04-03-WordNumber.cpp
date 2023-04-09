#include <iostream>
#include <cmath>
#include <unordered_map>
#include <vector>
#include <algorithm>

int main() {
	int cnt, result = 0;
	std::unordered_map<char, int> hash_map;
	std::cin >> cnt;

	for (int i = 0; i < cnt; i++) {
		std::string str;
		std::cin >> str;
		int num = str.length();
		for (char c : str) {
			num--;
			auto item = hash_map.find(c);
			if (item != hash_map.end()) {
				hash_map[c] += std::pow(10, num);
			}
			else {
				hash_map[c] = std::pow(10, num);
			}
		}
	}
	std::vector<int> vec;
	
	for (auto item : hash_map) {
		vec.push_back(item.second);
	}
	std::sort(vec.begin(), vec.end(),std::greater<int>());
	
	int num = 9;
	for (auto item : vec) {
		result += item * num;
		num--;
	}
	std::cout << result;

	return 0;
}