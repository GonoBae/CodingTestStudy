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
// 구역 개수
int areaCount = 0;
// 넓이
int area = 0;

vector<int> answer;

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

void dfs(int w, int h, int& count)
{
	count++;
	visited[w][h] = true;

	for (int i = 0; i < 4; i++)
	{
		int nh = h + dy[i];
		int nw = w + dx[i];

		if (nw >= 0 && nh >= 0 && nw <= MAX_SIZE && nh <= MAX_SIZE)
		{
			if (graph[nw][nh] == 1 && !visited[nw][nh])
			{
				visited[nw][nh] = true;
				dfs(nw, nh, count);
			}
		}
	}
}

int main() {
	int m, n, k;
	memset(visited, false, sizeof(visited));

	// 100 이하의 자연수
	cin >> m >> n >> k;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (i == 0 || j == 0) continue;
			graph[i][j] = 1;
		}
	}

	for (int i = 0; i < k; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int xw = x1+1; xw <= x2; xw++)
		{
			for (int yw = y1+1; yw <= y2; yw++)
			{
				graph[xw][yw] = 0;
			}
		}
	}

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (graph[j][i] ==1 && !visited[j][i])
			{
				areaCount++;
				area = 0;
				dfs(j, i, area);
				answer.push_back(area);
			}
		}
	}

	sort(answer.begin(), answer.end());

	cout << areaCount << endl;
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}

	return 0;
}
