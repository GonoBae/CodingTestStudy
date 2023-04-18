#include <iostream>
#include <vector>

using namespace std;


int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { 0, 1, -1, 1, -1, 0, 1, -1 };
int island[51][51];

void dfs(int _maxRow, int _maxColumn, int _x, int _y)
{
	island[_y][_x] = 0; // 바다 (방문처리)

	for (int i = 0; i < 8; ++i) 
	{
		int nextX = dx[i] + _x;
		int nextY = dy[i] + _y;

		if (0 <= nextX && nextX < _maxColumn && 0 <= nextY && nextY < _maxRow)
		{
			if (island[nextY][nextX]) { dfs(_maxRow, _maxColumn, nextX, nextY); }
		}
	}
}

int main()
{
	while (true)
	{
		int w, h;
		int cnt = 0;
		cin >> w >> h;

		// 종료 조건
		if (w == 0 && h == 0) { break; }

		// 지도 제작
		for (int row = 0; row < h; ++row)
		{
			for (int column = 0; column < w; ++column)
			{
				island[row][column] = 0;
				cin >> island[row][column];
			}
		}

		// 섬 탐색
		for (int row = 0; row < h; ++row)
		{
			for (int column = 0; column < w; ++column)
			{
				// 바다(0)가 아니면 방문
				if (island[row][column]) { dfs(h, w, column, row); ++cnt; }
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}