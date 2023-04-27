#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> graph[10001];

//void dfs(int _start, int& _cnt)
//{
//	_cnt += 1;
//	for (int i = 0; i < graph[_start].size(); ++i)
//	{
//		dfs(graph[_start][i], _cnt);
//	}
//}

void bfs(int _start, int& _cnt)
{
	queue<int> q;
	q.push(_start);
	_cnt += 1;

	while (!q.empty())
	{
		_start = q.front();
		q.pop();

		for (int i = 0; i < graph[_start].size(); ++i)
		{
			q.push(graph[_start][i]);
			_cnt += 1;
		}
	}
}

bool mycomp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second) { return a.first < b.first; }

	return a.second > b.second;
}

int main()
{
	int n, m;
	cin >> n >> m;

	// 신뢰관계 형성
	for (int i = 0; i < m; ++i)
	{
		int from, to;
		cin >> to >> from;

		graph[from].push_back(to);
	}

	// dfs 탐색
	vector<pair<int, int>> counts;
	for (int i = 1; i <= n; ++i)
	{
		int cnt = 0;
		bfs(i, cnt);
		counts.push_back({ i, cnt });
	}

	// 오름차순
	sort(counts.begin(), counts.end(), mycomp);

	// 최댓값 출력
	for (int i = 0; i < counts.size(); ++i)
	{
		if (counts[0].second > counts[i].second) { return 0; }

		cout << counts[i].first << '\n';
	}

	return 0;
}