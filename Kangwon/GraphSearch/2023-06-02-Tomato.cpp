#include <iostream>
#include <queue>
#include <vector>

bool chkRange(int M, int N, int x, int y);
int main()
{

	int M, N;
	std::cin >> M >> N;

	std::vector<std::vector<int>> container;
	for (int i = 0; i < N; i++)
	{
		std::vector<int> tmp;
		for (int j = 0; j < M; j++)
		{
			int input;
			std::cin >> input;
			tmp.push_back(input);
		}
		container.push_back(tmp);
	}

	std::queue<int> que_X;
	std::queue<int> que_Y;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (container[i][j] == 1)
			{
				que_X.push(j);
				que_Y.push(i);
			}
		}
	}

	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, -1, 0, 1 };

	while (!que_X.empty())
	{
		for (int i = 0; i < 4; i++)
		{
			if (chkRange(M, N, que_X.front() - dx[i], que_Y.front() - dy[i]))
			{
				if (container[que_Y.front() - dy[i]][que_X.front() - dx[i]] == 0)
				{
					container[que_Y.front() - dy[i]][que_X.front() - dx[i]] = container[que_Y.front()][que_X.front()] + 1;
					que_X.push(que_X.front() - dx[i]);
					que_Y.push(que_Y.front() - dy[i]);
				}
			}
		}
		que_X.pop();
		que_Y.pop();
	}

	int max = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (max < container[i][j]) {
				max = container[i][j];
			}
			if (container[i][j] == 0) {
				std::cout << -1;
				return 0;
			}
		}
	}
	std::cout << max - 1;
	return 0;
}

bool chkRange(int M, int N, int x, int y)
{
	return x >= 0 && y >= 0 && x < M && y < N;
}