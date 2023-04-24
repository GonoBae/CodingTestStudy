#include<iostream>
#include <queue>
#include <vector>

void BFS(const std::vector<std::vector<bool>>& array, std::vector<bool>& chk, int start);

int main() {
    int point, cnt;

    std::cin >> point >> cnt;

    std::vector<std::vector<bool>> array(point, std::vector<bool>(point, false));

    for (int i = 0; i < cnt; i++) {
        int a, b;
        std::cin >> a >> b;
        array[a - 1][b - 1] = true;
        array[b - 1][a - 1] = true;
    }

    std::vector<bool> chk(point, false);
    int result=0;
    for(int i =0;i<point;i++){
        if(!chk[i]){
            BFS(array, chk, i);
            result++;
        }
    }
    std::cout<<result;

    return 0;
}

void BFS(const std::vector<std::vector<bool>>& array, std::vector<bool>& chk, int start) {
    chk[start] = true;
    
    std::queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        for (int i = 0; i < array[start].size(); i++) {
            if (array[q.front()][i] == true && chk[i] == false) {
                q.push(i);
                chk[i] = true;
            }
        }

        q.pop();
        if(!q.empty())
            start=q.front();
    }
}
