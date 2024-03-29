#include<iostream>
#include <algorithm>
#include <queue>
#include <vector>

int DFS(const std::vector<std::vector<bool>>& array, std::vector<bool>& chk, int start);
int BFS(const std::vector<std::vector<bool>>& array, std::vector<bool>& chk, int start);

int main() {
	int point, cnt;
	std::vector<int> a;
	std::cin >> point >> cnt;

	std::vector<std::vector<bool>> array(point, std::vector<bool>(point, false));

	for (int i = 0; i < cnt; i++) {
		int a, b;
		std::cin >> a >> b;
		array[b - 1][a - 1] = true;
	}

	for (int i = 0; i < point; i++) {
		std::vector<bool> chk(point, false);
		a.push_back(DFS(array, chk, i));
	}
	
	int max = *std::max_element(a.begin(), a.end());

	for (int i = 0; i < point; i++) {
		if (a[i] == max) {
			std::cout << i + 1 << " ";
		}
	}

	return 0;
}

int DFS(const std::vector<std::vector<bool>>& array, std::vector<bool>& chk, int start) {
	int result = 0, max = 0;
	chk[start] = true;

	for (int i = 0; i < chk.size(); i++) {
		if (array[start][i] == true && chk[i] == false) {
			result++;
			int tmp = DFS(array, chk, i);
			if (max < tmp) {
				max = tmp;
			}
		}
	}
	result += max;

	return result;
}

int BFS(const std::vector<std::vector<bool>>& array, std::vector<bool>& chk, int start)
{
	int result = 0;
	chk[start] = true;
	std::queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		for (int i = 0; i < chk.size(); i++) {
			if (array[q.front()][i] == true && chk[i] == false) {
				q.push(i);
				chk[i] = true;
				
			}
		}
		result++;
		q.pop();
	}

	return result;
}
