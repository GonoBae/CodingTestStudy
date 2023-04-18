#include <iostream>
#include <vector>

using namespace std;

vector<int> network[101];
bool visited[101];
int virus = 0;

void dfs(int _start)
{
	visited[_start] = true;
	++virus;

	for (int i = 0; i < network[_start].size(); ++i)
	{
		int next = network[_start][i];
		if (!visited[next])
		{
			dfs(network[_start][i]);
		}
	}
}

int main()
{
	int computers;
	cin >> computers;

	int links;
	cin >> links;

	// 연결
	for (int i = 0; i < links; ++i)
	{
		int comp1, comp2;
		cin >> comp1 >> comp2;

		network[comp1].push_back(comp2);
		network[comp2].push_back(comp1);
	}

	dfs(1);

	int answer = 0;
	if (virus == 0) { answer = 0; }
	else { answer = virus-1; }

	cout << answer;

	return 0;
}