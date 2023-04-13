#include<iostream>
#include <queue>

void DFS(bool** array, bool* chk, int point, int start);
void BFS(bool** array, bool* chk, int point, int start);

int main() {
    int point, cnt, start;

    std::cin >> point >> cnt >> start;

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

    bool* chk1 = new bool[point]();
    DFS(array, chk1, point, start-1);
    
    std::cout << std::endl;

    bool* chk2 = new bool[point]();
    BFS(array, chk2, point, start - 1);

    return 0;
}

void DFS(bool** array, bool* chk, int point, int start) {
    chk[start] = true;
    std::cout << start + 1 << " ";

    for (int i = 0; i < point; i++) {
        if (array[start][i] == true && chk[i] == false) {
            
            DFS(array, chk, point, i);
        }
    }

}

void BFS(bool** array, bool* chk, int point, int start) {
    chk[start] = true;
    std::cout << start + 1 << " ";
    
    std::queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        for (int i = 0; i < point; i++) {
            if (array[q.front()][i] == true && chk[i] == false) {
                q.push(i);
                chk[i] = true;
                std::cout << i + 1 << " ";
            }
        }

        q.pop();
    }
}