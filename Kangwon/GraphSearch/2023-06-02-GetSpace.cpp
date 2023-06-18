#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int main()
{
    int M, N, K;
    std::cin >> M >> N >> K;
    // 모눈종이를 배열 통해 그린다
    std::vector<std::vector<bool>> array(M, std::vector<bool>(N, false));
    // 방문 검사를 위한 배열
    std::vector<std::vector<bool>> vis(M, std::vector<bool>(N, false));

    for (int cnt = 0; cnt < K; cnt++)
    {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        for (int i = y1; i < y2; i++)
        {
            for (int j = x1; j < x2; j++)
            {
                array[i][j] = true;
            }
        }
    }
    
    int dx[4] = { 1, 0, -1, 0 };
    int dy[4] = { 0, 1, 0, -1 };

    int count = 0; 
    std::vector<int> ans; 

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            
            //빈칸이고 방문도했으면 넘어감
            if (array[i][j] == 1 || vis[i][j] == 1) continue;
            
            std::queue<std::pair<int, int>> q;
            vis[i][j] = 1;
            q.push({ i,j });
            count++;
            int area = 1;
            while (!q.empty()) {
                auto cur = q.front();
                q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    // 모눈종이 밖으로 벗어나지 않았는지 검사
                    if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
                    
                    if (array[nx][ny] == 1 || vis[nx][ny] == 1) continue;
                    q.push({ nx,ny });
                    vis[nx][ny] = 1;
                    area++;
                }
            }
            ans.push_back(area);
        }
    }
    
    std::sort(ans.begin(), ans.end());
    std::cout << count << '\n';
    for (int i : ans)
        std::cout << i << ' ';
    return 0;
}