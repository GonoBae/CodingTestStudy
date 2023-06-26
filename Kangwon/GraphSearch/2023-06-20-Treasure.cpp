#include <iostream>
#include <vector>
#include <queue>

int x, y;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int BFS(int start_x, int start_y, const std::vector<std::vector<bool>> container);
int main()
{
	std::cin >> y >> x;
	std::vector<std::vector<bool>> container(y, std::vector<bool>(x, false));

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			char intput;
			std::cin >> intput;

			if (intput == 'L')
			{
				container[i][j] = true;
			}
			else
			{
				container[i][j] = false;
			}
		}
	}
	int max =0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (container[i][j])
			{
				int tmp = BFS(i, j, container);
				if(max<tmp){
					max =tmp;
				}
			}
		}
	}
	std::cout<<max;

	return 0;
}
int BFS(int start_y, int start_x, const std::vector<std::vector<bool>> container)
{
	std::vector<std::vector<int>> chk_box(y, std::vector<int>(x, -1));
	std::queue<std::pair<int, int>> que;

	chk_box[start_y][start_x] = 0;
	que.push(std::make_pair(start_y, start_x));
	int max = 0;

	while (!que.empty())
	{
		for (int i = 0; i < 4; i++)
		{
			if (que.front().second + dx[i] < x && que.front().first + dy[i] < y && que.front().second + dx[i] >= 0 && que.front().first + dy[i] >= 0)
			{
				if (container[que.front().first + dy[i]][que.front().second + dx[i]] && chk_box[que.front().first + dy[i]][que.front().second + dx[i]] == -1)
				{
					que.push(std::make_pair(que.front().first + dy[i], que.front().second + dx[i]));
					chk_box[que.front().first + dy[i]][que.front().second + dx[i]] = chk_box[que.front().first][que.front().second] + 1;
					if (max < chk_box[que.front().first + dy[i]][que.front().second + dx[i]])
					{
						max = chk_box[que.front().first + dy[i]][que.front().second + dx[i]];
					}
				}
			}
		}
		que.pop();
	}
	return max;
}