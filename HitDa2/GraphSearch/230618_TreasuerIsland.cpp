#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <utility>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
#define MAX_SIZE 51

int graph[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

// 상좌하우
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int l, w, cnt;

void bfs(int x, int y)
{
	int path = 0;

	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[x][y] = true;

	while (!q.empty())
	{
		int qsize = q.size();
		for (int p = 0; p < qsize; p++)
		{
			int cur_X = q.front().first;
			int cur_Y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int new_X = cur_X + dx[i];
				int new_Y = cur_Y + dy[i];

				if (new_X >= 0 && new_Y >= 0 && new_X < w && new_Y < l)
				{
					if (graph[new_X][new_Y] == 1 && visited[new_X][new_Y] == false)
					{
						q.push(make_pair(new_X, new_Y));
						visited[new_X][new_Y] = true;
					}
				}
			}
		}
		++path;
	}
	if (cnt < path - 1)
	{
		cnt = path - 1;
	}
}

int main() {
	// 세로, 가로
	cin >> l >> w;
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < w; j++)
		{
			char c;
			cin >> c;
			if (c == 'W')
			{
				graph[j][i] = 0;
			}
			else if (c == 'L')
			{
				graph[j][i] = 1;
			}
		}
	}

	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (graph[j][i] == 1)
			{
				memset(visited, 0, sizeof(visited));
				bfs(j, i);
			}
		}
	}

	cout << cnt << endl;


	return 0;
}