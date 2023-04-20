#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int area[101][101];
int copyArea[101][101];
vector<int> safetyArea;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void dfs(int _size, int _rain, int _x, int _y)
{
	copyArea[_y][_x] = -1;
	for (int i = 0; i < 4; ++i)
	{
		int nextX = _x + dx[i];
		int nextY = _y + dy[i];

		if (0 <= nextX && nextX < _size && 0 <= nextY && nextY < _size)
		{
			if (copyArea[nextY][nextX] > _rain)
			{
				dfs(_size, _rain, nextX, nextY);
			}
		}
	}
}

void copy(int _size)
{
	for (int row = 0; row < _size; ++row)
	{
		for (int column = 0; column < _size; ++column)
		{
			copyArea[row][column] = area[row][column];
		}
	}
}

int main()
{
	int n;
	cin >> n;

	// 맵 입력
	for (int row = 0; row < n; ++row)
	{
		for (int column = 0; column < n; ++column)
		{
			cin >> area[row][column];
		}
	}

	// 강수량에 따른 지역 크기
	for (int rain = 0; rain <= 100; ++rain)
	{
		int cnt = 0;
		copy(n);

		for (int row = 0; row < n; ++row)
		{
			for (int column = 0; column < n; ++column)
			{
				if (copyArea[row][column] > rain)
				{
					++cnt;
					dfs(n, rain, column, row);
				}
			}
		}

		safetyArea.push_back(cnt);
	}

	// 최대 값 출력
	cout << *max_element(safetyArea.begin(), safetyArea.end());

	return 0;
}ㅇ
