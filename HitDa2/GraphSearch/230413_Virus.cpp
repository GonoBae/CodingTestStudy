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
    int v = 1;
    cin >> n >> m;

    vector<int>* graph = new vector<int>[n+1];
    bool* check = new bool[n+1];
    fill(check, check + n + 1, false);
    int count = 0;

    for (int i = 0; i < m; i++)
    {
        int first, second;
        cin >> first >> second;

        graph[first].push_back(second);
        graph[second].push_back(first);
    }

    for (int i = 1; i <= n; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }


    // - DFS -> stack으로 구현
    stack<int> s;
    s.push(v);
    check[v] = true;
    while (!s.empty())
    {
        int current_node = s.top();
        s.pop();
        for (int i = 0; i < graph[current_node].size(); i++)
        {
            int next_node = graph[current_node][i];
            if (check[next_node]==false)
            {
                //cout << next_node << " ";
                check[next_node] = true;
                s.push(current_node);
                s.push(next_node);
                count++;
                break;
            }
        }
    }
    cout << count << endl;

    return 0;
}