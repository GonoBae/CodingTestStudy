#include <iostream>
#include <queue>
#include <vector>

int main() {

	int cnt, answer = 0;
	bool zero = false;
	std::cin >> cnt;

	std::priority_queue<int> Pn;
	std::priority_queue<int, std::vector<int>, std::greater<int>> Nn;

	while(cnt > 0)
	{		
		int num;
		std::cin >> num;

		if (num > 0) {
			Pn.push(num);
		}
		else if(num<0) {
			Nn.push(num);
		}
		else {
			zero = true;
		}
		cnt--;
	}

	while (Pn.size() > 1)
	{
		int a, b;
		a = Pn.top();
		Pn.pop();
		b = Pn.top();
		Pn.pop();
		if (a == 1 || b == 1) {
			answer += (a + b);
		}
		else {
			answer += a * b;
		}
		
	}
	
	while (Nn.size() > 1)
	{
		int a, b;
		a = Nn.top();
		Nn.pop();
		b = Nn.top();
		Nn.pop();
		answer += a * b;
	}

	if (Pn.size() == 1) {
		answer += Pn.top();
	}
	if (!zero && Nn.size() == 1) {
		answer += Nn.top();
	}

	std::cout << answer;
	return 0;
}