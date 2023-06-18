#include <iostream>
#include <vector>
#include <queue>

#define MAX 1001
#define INF 987654321

std::vector<int> dijkstra(int start, int V, std::vector<std::pair<int, int>> adj[])
{
	std::vector<int> dist(V, INF);
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int, int>>> pq;

	dist[start] = 0;
	pq.push(std::make_pair(0, start));

	while (!pq.empty())
	{
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost)
			continue;

		for (int i = 0; i < adj[cur].size(); i++)
		{
			int next = adj[cur][i].first;
			int nCost = cost + adj[cur][i].second;
			if (nCost < dist[next])
			{
				dist[next] = nCost;
				pq.push(std::make_pair(nCost, next));
			}
		}
	}

	return dist;
}

int main()
{
	int V, E;
	std::vector<std::pair<int, int>> adj[MAX];
	std::cin >> V;
	std::cin >> E;

	for (int i = 0; i < E; i++)
	{
		int from, to, cost;
		std::cin >> from >> to >> cost;
		adj[from - 1].push_back(std::make_pair(to - 1, cost));
	}
	int start, end;
	std::cin >> start >> end;
	std::vector<int> dist = dijkstra(start - 1, V, adj);

	std::cout << dist[end - 1];

	return 0;
}
