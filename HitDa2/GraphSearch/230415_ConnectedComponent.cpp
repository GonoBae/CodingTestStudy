#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <utility>
#include <queue>
#include <stack>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;

    vector<int>* graph = new vector<int>[n+1];
    bool* check = new bool[n+1];
    fill(check, check + n + 1, false);
    int count = 0;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    for (int i = 1; i <= n; i++)
    {
        if (!check[i])
        {
            stack<int> s;
            s.push(i);
            check[i] = true;
            while (!s.empty())
            {
                int current_node = s.top();
                s.pop();
                for (int i = 0; i < graph[current_node].size(); i++)
                {
                    int next_node = graph[current_node][i];
                    if (check[next_node] == false)
                    {
                        check[next_node] = true;
                        s.push(current_node);
                        s.push(next_node);
                        break;
                    }
                }
            }
            count++;
        }
    }

    cout << count << endl;

    return 0;
}