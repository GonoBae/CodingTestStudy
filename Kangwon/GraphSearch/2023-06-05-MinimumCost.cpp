#include <vector>
#include <iostream>
#include <queue>

#define MAX 1000        // 최대 정점의 개수 
#define INF 100001

using namespace std;

vector<int> dijkstra(int start, int V, vector<pair<int, int> > adj[]) {
	vector<int> dist(V, INF);
	priority_queue<pair<int, int> > pq;

	dist[start] = 0;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int cost = -pq.top().first;    // 방문한 정점의 dist 값 
		int cur = pq.top().second;    // 현재 방문한 정점 
		pq.pop();

		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i].first;
			int nCost = cost + adj[cur][i].second;
			if (nCost < dist[next]) {
				dist[next] = nCost;
				pq.push(make_pair(-nCost, next));
			}
		}
	}

	return dist;
}

int main()
{
	int V, E;
	vector<pair<int, int> > adj[MAX];
	cin >> V;
	cin >> E;

	for (int i = 0; i < E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		adj[from].push_back(make_pair(to - 1, cost));
		adj[to].push_back(make_pair(from - 1, cost));
	}

	int S, E;
	cin >> S >> E;
	
	vector<int> dist = dijkstra(S-1, V, adj);
	

	return 0;
}
