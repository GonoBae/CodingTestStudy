#include <iostream>
#include <vector>

void DFS(std::vector<std::vector<bool>>& array, int col, int row);

int main()
{
	int point;
	std::cin >> point;

	std::vector<std::vector<int>> array(point, std::vector<int>(point, 0));

	int max = 0;
	for (int i = 0; i < point; i++)
	{
		for (int j = 0; j < point; j++)
		{
			int chk;
			std::cin >> chk;
			if (max < chk)
				max = chk;
			array[i][j] = chk;
		}
	}
	int result_max = 0;
	for (int k = 0; k <= max; k++)
	{
		std::vector<std::vector<bool>> array_chk(point, std::vector<bool>(point, false));
		for (int i = 0; i < point; i++)
		{
			for (int j = 0; j < point; j++)
			{
				if (array[i][j] > k) {
					array_chk[i][j] = true;
				}
			}
		}

		int result = 0;
		for (int i = 0; i < point; i++)
		{
			for (int j = 0; j < point; j++)
			{
				if (array_chk[i][j]) {
					DFS(array_chk, i, j);
					result++;
				}
			}
		}
		if (result_max < result)
			result_max = result;

	}

	std::cout << result_max;

	return 0;
}

void DFS(std::vector<std::vector<bool>>& array, int col, int row)
{

	if (array[col][row])
	{
		array[col][row] = false;
		if (array.size() > col + 1)
		{
			DFS(array, col + 1, row);
		}
		if (array[0].size() > row + 1)
		{
			DFS(array, col, row + 1);
		}
		if (0 <= col - 1)
		{
			DFS(array, col - 1, row);
		}
		if (0 <= row - 1)
		{
			DFS(array, col, row - 1);
		}
	}
}
