#include <iostream>
#include <vector>

using namespace std;

int paper[501][501];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int dfs(int _x, int _y, int _size)
{
	paper[_y][_x] = 0;
	
	for (int i = 0; i < 4; ++i)
	{
		int nextX = _x + dx[i];
		int nextY = _y + dy[i];

		if (0 <= nextX && nextX < 501 && 0 <= nextY && nextY < 501)
		{
			if (paper[nextY][nextX])
			{
				return dfs(nextX, nextY, _size+1);
			}
		}
	}

	return _size;
}

int main()
{
	int n, m;
	cin >> n >> m;

	// 도화지 입력
	for (int row = 0; row < n; ++row)
	{
		for (int column = 0; column < m; ++column)
		{
			cin >> paper[row][column];
		}
	}

	// 도화지 입력
	int paperCnt = 0;
	int maxSize = 0;
	for (int row = 0; row < n; ++row)
	{
		for (int column = 0; column < m; ++column)
		{
			if (paper[row][column])
			{
				++paperCnt;
				int current = dfs(column, row, 1);
				if (current > maxSize)
				{
					maxSize = current;
				}
			}
		}
	}

	cout << paperCnt << '\n';
	cout << maxSize;

	return 0;
}