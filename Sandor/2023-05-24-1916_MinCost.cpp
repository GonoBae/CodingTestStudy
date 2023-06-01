#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> city[1001];
int costs[1001];
//bool visited[1001];


/* 메모리 초과
void dfs(int _start, int _end, int _weight)
{
	// 목표 도달
	if (_start == _end) 
	{
		if (minCost == -1) { minCost = _weight; }
		else if (minCost > _weight) { minCost = _weight; }
		return;
	}

	// 다음 행선 (백트래킹)
	for (int i = 0; i < city[_start].size(); ++i)
	{
		
		int next = city[_start][i].first;
		int nextCost = city[_start][i].second;

		visited[next] = true;
		dfs(next, _end, _weight + nextCost);
		visited[next] = false;
	}
}
*/

// 시간초과
void bfs(int _start)
{
	queue<pair<int, int>> q;
	q.push({ _start, 0 });

	while (!q.empty())
	{
		int current = q.front().first;
		int currentCost = q.front().second;
		q.pop();

		for (int i = 0; i < city[current].size(); ++i)
		{
			int next = city[current][i].first;
			int totalCost = currentCost + city[current][i].second;

			if (totalCost < costs[next])
			{
				costs[next] = totalCost;
				q.push({next, totalCost});
			}
		}
	}
}

int main()
{
	// 도시, 버스 수
	int n, m;
	cin >> n >> m;

	// 간선 연결
	for (int i = 0; i < m; ++i)
	{
		int from, to, cost;
		cin >> from >> to >> cost;

		city[from].push_back({ to, cost });
	}

	// 목적지
	int start, end;
	cin >> start >> end;

	//visited[start] = true;
	//dfs(start, end, 0);

	for (int i = 0; i < 1001; ++i)
	{
		costs[i] = INT32_MAX;
	}
	bfs(start);

	// 최소비용
	//cout << minCost;
	cout << costs[end];

	return 0;
}