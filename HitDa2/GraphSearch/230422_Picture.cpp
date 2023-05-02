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
#define MAX_SIZE 500

int graph[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

// 상좌하우
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

void dfs(int w, int h, int& areaCount)
{
	areaCount++;
	visited[w][h] = true;

	for (int i = 0; i < 4; i++)
	{
		int nh = h + dy[i];
		int nw = w + dx[i];

		if (nw >= 0 && nh >= 0 && nw <= MAX_SIZE && nh <= MAX_SIZE)
		{
			if (graph[nw][nh]==1&& !visited[nw][nh])
			{
				visited[nw][nh] = true;
				dfs(nw, nh, areaCount);
			}
		}
	}
}

int main() {
	int m, n;
	int count = 0;
	int maxArea = 0;
	int area = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> graph[j][i];
		}
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (graph[j][i] == 1 && !visited[j][i])
			{
				count++;
				area = 0;
				dfs(j, i, area);
				if (maxArea < area)
				{
					maxArea = area;
				}
			}
		}
	}
	

	cout << count << endl;
	cout << maxArea << endl;

	return 0;
}
