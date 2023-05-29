#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[51][51];
int copyMap[51][51];
int visited[51][51];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
int maxRow, maxColumn;

queue<pair<int, int>> q;

int bfs(int _x, int _y, int _m, int _n)
{
	q.push({ _x, _y });
	visited[_y][_x] = true;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		maxColumn = x;
		maxRow = y;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextX = x + dx[i];
			int nextY = y + dy[i];

			if (0 <= nextX && nextX < _m && 0 <= nextY && nextY < _n)
			{
				if (copyMap[nextY][nextX] == 0 && !visited[nextY][nextX])
				{
					copyMap[nextY][nextX] = copyMap[y][x] + 1;
					visited[nextY][nextX] = true;
					q.push({ nextX, nextY });
				}
			}
		}
	}

	return copyMap[maxRow][maxColumn];
}

void Init(int _m, int _n)
{
	for (int i = 0; i < _n; i++)
	{
		for (int j = 0; j < _m; j++)
		{
			copyMap[i][j] = map[i][j];
			visited[i][j] = false;
		}
	}
}

int main()
{
	// 세로, 가로
	int n, m;
	cin >> n >> m;

	// 육지, 바다 배치 
	string temp;
	for (int row = 0; row < n; row++)
	{
		cin >> temp;
		for (int column = 0; column < m; column++)
		{
			// 바다는 -1로 등록하기
			if (temp[column] == 'W')
			{
				map[row][column] = -1;
			}
		}
	}

	// 모든 육지에 대해 bfs 탐색
	int maxCnt = 0;
	for (int row = 0; row < n; row++)
	{
		for (int column = 0; column < m; column++)
		{
			if (!map[row][column])
			{
				// 맵 복사 및 초기화
				Init(m, n);

				int cnt = bfs(column, row, m, n);

				if (maxCnt < cnt)
				{
					maxCnt = cnt;
				}
			}
		}
	}

	// 최댓값 출력
	cout << maxCnt;

	return 0;
}