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
#define MAX_SIZE 101

int graph[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

// 상좌하우
int dx[4] = { 0, -1, 0, 1};
int dy[4] = { -1, 0, 1, 0};

void dfs(int w, int h, int limit)
{
	visited[w][h] = true;

	for (int i = 0; i < 4; i++)
	{
		int nh = h + dy[i];
		int nw = w + dx[i];

		if (nw >= 0 && nh >= 0 && nw <= MAX_SIZE && nh <= MAX_SIZE)
		{
			if (graph[nw][nh] > limit && !visited[nw][nh])
			{
				visited[nw][nh] = true;
				dfs(nw, nh, limit);
			}
		}
	}
}

int main() {
	int n;
	int answer = 0;
	int safeGround = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[j][i];
		}
	}

	for (int k = 0; k <= 100; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (graph[j][i] > k && !visited[j][i])
				{
					safeGround++;
					dfs(j, i, k);
				}
			}
		}

		if (answer < safeGround)
		{
			answer = safeGround;
		}

		memset(visited, false, sizeof(visited));
		safeGround = 0;
	}

	cout << answer << endl;

	return 0;
}
