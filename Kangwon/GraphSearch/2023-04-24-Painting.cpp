#include <iostream>
#include <vector>

void BFS(std::vector<std::vector<bool>>& array, int col, int row);
int cnt = 0;

int main() {
	int row, col;
	std::cin >> col >> row;
	std::vector<std::vector<bool>> array(col, std::vector<bool>(row, false));

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			int chk;
			std::cin >> chk;
			array[i][j] = chk;
		}
	}

	int max = 0, result = 0;
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			BFS(array, i, j);
			if (cnt > 0) {
				if (max < cnt) {
					max = cnt;
				}
				result++;
				cnt = 0;
			}
		}
	}

	std::cout << result << std::endl;
	std::cout << max << std::endl;

	return 0;
}

void BFS(std::vector<std::vector<bool>>& array, int col, int row) {
	
	if (array[col][row]) {
		array[col][row] = false;
		cnt++;

		if (array.size() > col + 1) {
			BFS(array, col + 1, row);
		}
		if (array[0].size() > row + 1) {
			BFS(array, col, row + 1);
		}
		if (0 < col - 1) {
			BFS(array, col - 1, row);
		}
		if (0 < row - 1) {
			BFS(array, col, row - 1);
		}
	}
}
