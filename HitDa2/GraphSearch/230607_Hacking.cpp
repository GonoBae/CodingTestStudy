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
#define MAX_SIZE 10000

vector<int> graph[MAX_SIZE+1];
bool visited[MAX_SIZE+1];
int maxCount = 0;
int co = 0;

int answer[MAX_SIZE+1];

void dfs(int node)
{
	visited[node] = true;
	co++;
	for (int i = 0; i < graph[node].size(); i++)
	{
		int nextNode = graph[node][i];
		if (!visited[nextNode])
		{
			dfs(nextNode);
		}
	}
}

int main() {
	int m, n, a, b;

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		graph[b].push_back(a);
	}

	for (int i = 1; i < n+1; i++)
	{
		co = 0;
		dfs(i);
		if (maxCount < co)
		{
			maxCount = co;
		}
		memset(visited, false, sizeof(visited));
		answer[i] = co;
	}

	for (int i = 1; i < n+1; i++)
	{
		if (answer[i] == maxCount)
		{
			cout << i << " ";
		}
	}

	return 0;
}
