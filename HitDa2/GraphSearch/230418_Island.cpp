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
#define MAX_SIZE 50

int graph[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

// 좌측 상단 부터 반시계
int dx[8] = { -1,-1,-1, 0, 1,1,1,0 };
int dy[8] = { -1, 0, 1,1,1,0,-1,-1 };

void dfs(int w, int h)
{
	visited[w][h] = true;

	for (int i = 0; i < 8; i++)
	{
		int nh = h + dy[i];
		int nw = w + dx[i];

		if (nw >= 0 && nh >=0 && nw <= MAX_SIZE && nh <= MAX_SIZE)
		{
			if (graph[nw][nh] == 1 && !visited[nw][nh])
			{
				visited[nw][nh] = true;
				dfs(nw, nh);
			}
		}
	}
}

int main() {
	int w = -1,h = -1;
	int answer = 0;
	while (true)
	{
		cin >> w >> h;
		if (w==0&&h==0)
		{
			break;
		}

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> graph[j][i];
			}
		}

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (graph[j][i] == 1 && !visited[j][i])
				{
					answer++;
					dfs(j, i);
				}
			}
		}
		cout << answer << endl;

		memset(graph, false, sizeof(graph));
		memset(visited, false, sizeof(visited));
		answer = 0;
	}

    return 0;
}