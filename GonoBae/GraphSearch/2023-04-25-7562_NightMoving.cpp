#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
#define MAX 301
int n, m;
int a1, b1, a2, b2;
bool visited[MAX][MAX];
// 나이트의 이동
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

// Reset visited
void reset(int _m) {
    for(int i = 0; i < _m; ++i) {
        for(int j = 0; j < _m; ++j) {
            visited[i][j] = 0;
        }
    }
}

int bfs(int x, int y, int s) {
    queue<pair<pair<int, int>, int>> Q;
    visited[x][y] = true;
    Q.push( make_pair(make_pair(x, y), s) );
    while(!Q.empty()) {
        x = Q.front().first.first;
        y = Q.front().first.second;
        s = Q.front().second;
        if(x == a2 && y == b2) return s;
        Q.pop();
        for(int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= m || ny >= m) continue;
            if(visited[nx][ny]) continue;
            visited[nx][ny] = true;
            Q.push( make_pair(make_pair(nx, ny), s + 1) );
        }
    }
    return 0;
}
int main() {
    cin >> n;
    while(n--) {
        // 새로운 넓이의 판이 주어짐
        cin >> m;
        reset(m);
        // 출발, 도착
        cin >> a1 >> b1;
        cin >> a2 >> b2;
        
        cout << bfs(a1, b1, 0) << endl;
    }
    return 0;
}