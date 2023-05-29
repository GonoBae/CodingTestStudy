#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[101][101];
bool visited[101][101];
vector<int> weights;	// 넓이

int dColumn[4] = { -1, 0, 1, 0 };
int dRow[4] = { 0, -1 , 0, 1 };

void dfs(int _row, int _column, int _m, int _n, int& _weight)
{
	visited[_row][_column] = true;

	for (int i = 0; i < 4; ++i)
	{
		int nextRow = _row + dRow[i];
		int nextColumn = _column + dColumn[i];

		if (0 <= nextRow && nextRow < _m && 0 <= nextColumn && nextColumn < _n)
		{
			if (!visited[nextRow][nextColumn])
			{
				dfs(nextRow, nextColumn, _m, _n, ++_weight);
			}
		}
	}
}

int main()
{
	int m, n, k;
	cin >> m >> n >> k;

	for (int i = 0; i < k; ++i)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		// 사각형 그리기
		for (int row = y1; row < y2; ++row)
		{
			for (int column = x1; column < x2; ++column)
			{
				visited[row][column] = true;
			}
		}
	}

	// 빈칸 dfs 진행 
	int cnt = 0;
	for (int row = 0; row < m; ++row)
	{
		for (int column = 0; column < n; ++column)
		{
			if (visited[row][column]) { continue; }

			++cnt;
			int weight = 1;
			dfs(row, column, m, n, weight);
			weights.push_back(weight);
		}
	}

	// 오름차순 정렬
	sort(weights.begin(), weights.end());
	
	// 출력
	cout << cnt << '\n';
	for (int i = 0; i < weights.size(); ++i)
	{
		cout << weights[i] << ' ';
	}

	return 0;
}