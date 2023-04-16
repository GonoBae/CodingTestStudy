#include<iostream>
#include <queue>

void BFS(bool** array, bool* chk, int point, int start);

int main() {
    int point, cnt;

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
    int result=0;
    for(int i =0;i<point;i++){
        if(!chk[i]){
            BFS(array, chk, point, i);    
            result++;
        }
    }
    std::cout<<result;
    
    return 0;
}

void BFS(bool** array, bool* chk, int point, int start) {
    chk[start] = true;
    
    std::queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        for (int i = 0; i < point; i++) {
            if (array[q.front()][i] == true && chk[i] == false) {
                q.push(i);
                chk[i] = true;
            }
        }

        q.pop();
    }
}
