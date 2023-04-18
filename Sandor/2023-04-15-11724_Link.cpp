#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[1001];
bool visited[1001];
int cnt = 0;

void dfs(int _start)
{
	visited[_start] = true;

	for (int i = 0; i < graph[_start].size(); ++i)
	{
		int next = graph[_start][i];
		if (!visited[next])
		{
			dfs(graph[_start][i]);
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	// 간선 연결
	for (int i = 0; i < m; ++i)
	{
		int u,v;
		cin >> u >> v;

		// 양방향 연결
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	// n만큼 dfs 실행
	for (int i = 1; i <= n; ++i)
	{
		if (!visited[i])
		{
			dfs(i);
			++cnt;
		}
	}

	cout << cnt;

	return 0;
}