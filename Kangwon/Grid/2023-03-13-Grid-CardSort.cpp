#include <iostream>
#include <queue>
#include <vector>

int main() {

	int solution = 0;
	int cnt;
	std::cin >> cnt;
	
	std::priority_queue<int, std::vector<int>, std::greater<int>> PQ;
	
	for (int i = 0; i < cnt; i++) {
		int input;
		std::cin >> input;
		PQ.push(input);		
	}

	while (PQ.size() > 1)
	{
		int a, b;
		a = PQ.top();
		PQ.pop();
		b = PQ.top();
		PQ.pop();
		solution += a + b;
		PQ.push(a + b);
	}

	std::cout << solution;
	return 0;
}
