#include<iostream>
#include <queue>

int BFS(bool** array, bool* chk, int point, int start);

int main() {
    int point, cnt, start = 0;

    std::cin >> point >> cnt;

    bool** array = new bool* [point]();

    for (int i = 0; i < point; i++) {
        array[i] = new bool[point]();
    }

    for (int i = 0; i < cnt; i++) {
        int a, b;
        std::cin >> a >> b;
        array[a - 1][b - 1] = true;
        array[b - 1][a - 1] = true;
    }

    bool* chk = new bool[point]();
    std::cout<<BFS(array, chk, point, start );

    return 0;
}

int BFS(bool** array, bool* chk, int point, int start) {
    chk[start] = true;
    
    std::queue<int> q;
    q.push(start);
    int cnt = 0;

    while (!q.empty())
    {
        for (int i = 0; i < point; i++) {
            if (array[q.front()][i] == true && chk[i] == false) {
                q.push(i);
                chk[i] = true;
                cnt++;
            }
        }

        q.pop();
    }

    return cnt;
}
