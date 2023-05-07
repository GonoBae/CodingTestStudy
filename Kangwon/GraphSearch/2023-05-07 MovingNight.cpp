#include <iostream>
#include <vector>
#include <queue>
int BFS(std::vector<std::vector<bool>>& vec, int start_x, int start_y, int end_x, int end_y);

const std::vector<std::pair<int, int>> table{
	std::make_pair(1, 2),
	std::make_pair(2, 1),
	std::make_pair(2, -1),
	std::make_pair(1, -2),
	std::make_pair(-1, -2),
	std::make_pair(-2, -1),
	std::make_pair(-2, 1),
	std::make_pair(-1, 2) };

int main()
{
	int num;
	std::cin >> num;

	for (int i = 0; i < num; i++)
	{
		int len;
		std::cin >> len;
		std::vector<std::vector<bool>> vec(len, std::vector<bool>(len, false));
		int start_x, start_y, end_x, end_y;
		std::cin >> start_x >> start_y >> end_x >> end_y;

		std::cout << BFS(vec, start_x, start_y, end_x, end_y)<<std::endl;
	}
}

int BFS(std::vector<std::vector<bool>>& vec, int start_x, int start_y, int end_x, int end_y)
{
	vec[start_x][start_y] = true;

	std::queue<std::pair<int, int>> que;
	std::queue<int> que_num;
	que.push(std::make_pair(start_x, start_y));
	que_num.push(0);

	while (!que.empty())
	{
		if (que.front().first == end_x && que.front().second == end_y)
			return que_num.front();

		for (auto pair : table)
		{
			if (!(vec.size() <= que.front().first + pair.first || 0 > que.front().first + pair.first ||
				vec.size() <= que.front().second + pair.second || 0 > que.front().second + pair.second))
			{
				if (!vec[que.front().first + pair.first][que.front().second + pair.second])
				{
					vec[que.front().first + pair.first][que.front().second + pair.second] = true;
					que.push(std::make_pair(que.front().first + pair.first, que.front().second + pair.second));
					que_num.push(que_num.front() + 1);
				}
			}
		}

		que.pop();
		que_num.pop();
	}

	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
int BFS(std::vector<std::vector<bool>>& vec, int start_x, int start_y, int end_x, int end_y);

const std::vector<std::pair<int, int>> table{
	std::make_pair(1, 2),
	std::make_pair(2, 1),
	std::make_pair(2, -1),
	std::make_pair(1, -2),
	std::make_pair(-1, -2),
	std::make_pair(-2, -1),
	std::make_pair(-2, 1),
	std::make_pair(-1, 2) };

int main()
{
	int num;
	std::cin >> num;

	for (int i = 0; i < num; i++)
	{
		int len;
		std::cin >> len;
		std::vector<std::vector<bool>> vec(len, std::vector<bool>(len, false));
		int start_x, start_y, end_x, end_y;
		std::cin >> start_x >> start_y >> end_x >> end_y;

		std::cout << BFS(vec, start_x, start_y, end_x, end_y)<<std::endl;
	}
}

int BFS(std::vector<std::vector<bool>>& vec, int start_x, int start_y, int end_x, int end_y)
{
	vec[start_x][start_y] = true;

	std::queue<std::pair<int, int>> que;
	std::queue<int> que_num;
	que.push(std::make_pair(start_x, start_y));
	que_num.push(0);

	while (!que.empty())
	{
		if (que.front().first == end_x && que.front().second == end_y)
			return que_num.front();

		for (auto pair : table)
		{
			if (!(vec.size() <= que.front().first + pair.first || 0 > que.front().first + pair.first ||
				vec.size() <= que.front().second + pair.second || 0 > que.front().second + pair.second))
			{
				if (!vec[que.front().first + pair.first][que.front().second + pair.second])
				{
					vec[que.front().first + pair.first][que.front().second + pair.second] = true;
					que.push(std::make_pair(que.front().first + pair.first, que.front().second + pair.second));
					que_num.push(que_num.front() + 1);
				}
			}
		}

		que.pop();
		que_num.pop();
	}

	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
int BFS(std::vector<std::vector<bool>>& vec, int start_x, int start_y, int end_x, int end_y);

const std::vector<std::pair<int, int>> table{
	std::make_pair(1, 2),
	std::make_pair(2, 1),
	std::make_pair(2, -1),
	std::make_pair(1, -2),
	std::make_pair(-1, -2),
	std::make_pair(-2, -1),
	std::make_pair(-2, 1),
	std::make_pair(-1, 2) };

int main()
{
	int num;
	std::cin >> num;

	for (int i = 0; i < num; i++)
	{
		int len;
		std::cin >> len;
		std::vector<std::vector<bool>> vec(len, std::vector<bool>(len, false));
		int start_x, start_y, end_x, end_y;
		std::cin >> start_x >> start_y >> end_x >> end_y;

		std::cout << BFS(vec, start_x, start_y, end_x, end_y)<<std::endl;
	}
}

int BFS(std::vector<std::vector<bool>>& vec, int start_x, int start_y, int end_x, int end_y)
{
	vec[start_x][start_y] = true;

	std::queue<std::pair<int, int>> que;
	std::queue<int> que_num;
	que.push(std::make_pair(start_x, start_y));
	que_num.push(0);

	while (!que.empty())
	{
		if (que.front().first == end_x && que.front().second == end_y)
			return que_num.front();

		for (auto pair : table)
		{
			if (!(vec.size() <= que.front().first + pair.first || 0 > que.front().first + pair.first ||
				vec.size() <= que.front().second + pair.second || 0 > que.front().second + pair.second))
			{
				if (!vec[que.front().first + pair.first][que.front().second + pair.second])
				{
					vec[que.front().first + pair.first][que.front().second + pair.second] = true;
					que.push(std::make_pair(que.front().first + pair.first, que.front().second + pair.second));
					que_num.push(que_num.front() + 1);
				}
			}
		}

		que.pop();
		que_num.pop();
	}

	return 0;
}
