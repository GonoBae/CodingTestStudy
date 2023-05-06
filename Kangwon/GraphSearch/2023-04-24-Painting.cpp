#include <iostream>
#include <vector>

void DFS(std::vector<std::vector<bool>>& array, int col, int row, int& cnt);

int main()
{
	int row, col;
	std::cin >> col >> row;
	std::vector<std::vector<bool>> array(col, std::vector<bool>(row, false));

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			int chk;
			std::cin >> chk;
			array[i][j] = chk;
		}
	}

	int max = 0, result = 0;
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			int cnt = 0;
			DFS(array, i, j, cnt);
			if (cnt > 0)
			{
				if (max < cnt)
				{
					max = cnt;
				}
				result++;
			}
		}
	}

	std::cout << result << std::endl;
	std::cout << max << std::endl;

	return 0;
}

void DFS(std::vector<std::vector<bool>>& array, int col, int row, int& cnt)
{

	if (array[col][row])
	{
		array[col][row] = false;
		cnt++;

		if (array.size() > col + 1)
		{
			DFS(array, col + 1, row, cnt);
		}
		if (array[0].size() > row + 1)
		{
			DFS(array, col, row + 1, cnt);
		}
		if (0 <= col - 1)
		{
			DFS(array, col - 1, row, cnt);
		}
		if (0 <= row - 1)
		{
			DFS(array, col, row - 1, cnt);
		}
	}
}
