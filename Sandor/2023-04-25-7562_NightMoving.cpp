#include <iostream>
#include <queue>

using namespace std;

int chess[300][300];
int dx[8] = { -2, -2, -1, -1, 1, 1 ,2 ,2 };
int dy[8] = { -1, 1, -2, 2, -2, 2,-1, 1 };

int bfs(const int& _size, const pair<int, int>& _start, const pair<int, int>& _goal)
{
	queue<pair<int, int>> q;
	q.push({ _start });
	chess[_start.second][_start.first] = 1;

	while (!q.empty())
	{
		pair<int, int> coord = q.front();
		q.pop();

		for (int i = 0; i < 8; ++i)
		{
			int nextX = coord.first + dx[i];
			int nextY = coord.second + dy[i];

			if (0 <= nextX && nextX < _size && 0 <= nextY && nextY < _size)
			{
				if (!chess[nextY][nextX])
				{
					q.push({ nextX, nextY });
					chess[nextY][nextX] += chess[coord.second][coord.first] + 1;

					// 목표 지점과 일치하다면 종료
					if (nextX == _goal.first && nextY == _goal.second)
					{
						return chess[nextY][nextX] - 1;
					}
				}
			}
		}
	}

	return 0;
}

void InitChess(const int& _size)
{
	for (int row = 0; row < _size; ++row)
	{
		for (int column = 0; column < _size; ++column)
		{
			chess[row][column] = 0;
		}
	}
}

int main()
{
	int t;
	cin >> t;

	while (t)
	{
		--t;

		// 체스판 크기
		int l;
		cin >> l;

		// 나이트의 시작, 목표 지점
		int startX, startY, goalX, goalY;
		cin >> startX >> startY;
		cin >> goalX >> goalY;

		// 탐색
		int answer = 0;
		if (startX == goalX && startY == goalY) { answer = 0; }
		else 
		{
			answer = bfs(l, { startX, startY }, {goalX, goalY});
		}
		cout << answer;
		InitChess(l);
	}

	return 0;
}