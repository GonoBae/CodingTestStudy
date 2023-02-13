#include <string>
#include <vector>
#include <iostream>

//brute force
std::vector<int> solution(std::vector<int> lottos, std::vector<int> win_nums) {
	std::vector<int> answer;
	int cnt = 0;
	int zero = 0;
	for (int i : lottos) {
		if (i == 0) {
			zero++;
			continue;
		}
		for (int j : win_nums) {
			if (i == j) cnt++;
		}
	}

	answer.push_back(cnt == 0 || zero == 0 ? 6 : 7 - (cnt + zero));
	answer.push_back(cnt == 0 ? 6 : 7 - cnt);

	return answer;
}

int main() {

	std::vector<int> lottos = { 44, 8, 2, 3, 31, 25 };
	std::vector<int> win_nums = { 31, 10, 45, 1, 6, 19 };
	solution(lottos, win_nums);
}