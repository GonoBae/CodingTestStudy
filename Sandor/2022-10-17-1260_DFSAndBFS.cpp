#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>

#define MAX 1001

using namespace std;

// 입력값: 정점의 수(n), 간선의 수(m), 시작 점(v)
int n, m, v;
vector<int> graph[MAX];
bool visited[MAX];

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    cout << start << ' ';

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        
        // 다음 노드 방문 확인
        for (int i = 0; i < graph[x].size(); i++)
        {
            int next = graph[x][i];

            if (!visited[next])
            {
                q.push(next);
                visited[next] = true;
                cout << next << ' ';
            }
        }
    }
}

void dfs(int start)
{
    visited[start] = true;
    cout << start << ' ';

    // 다음 노드 방문 확인
    for (int i = 0; i < graph[start].size(); i++)
    {
        int next = graph[start][i];
        if (!visited[next])
        {
            dfs(next);
        }
    }
}

int main()
{ 
    cin >> n >> m >> v;

    // 간선 연결
    for (int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;
       
        // 양방향 연결
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    // 작은 수 먼저 방문을 위한 정렬
    for (int i = 0; i < MAX; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    // dfs 실행
    dfs(v);

    // 방문 처리 초기화
    cout << '\n';
    memset(visited, false, sizeof(visited));

    // bfs 실행
    bfs(v);


    return 0;
}