#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    // t만큼 반복
    while (t--)
    {
        int answer = 1;

        // 지원자 수
        int n;
        cin >> n;

        vector<pair<int, int>> grade;      // <서류 성적, 면접 성적>
        for (int i = 0; i < n; ++i)
        {
            int first, second;
            cin >> first >> second;
            grade.push_back({ first, second });
        }

        // 서류 성적 기준으로 오름차순 정렬
        sort(grade.begin(), grade.end());

        // ---- (참고한 부분) ----
        int prevScore = grade[0].second; // 이전 면접자의 성적 (처음: 1위의 성적)

        for (int i = 1; i < n; ++i)
        {
            // 이전 지원자의 면접 성적보다 높은 성적을 가진 지원자가 있다면 
            if (grade[i].second < prevScore)
            {
                ++answer;
                prevScore = grade[i].second;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}

/*

1 4
2 5 
3 6 
4 2 
5 7 
6 1 
7 3 

*/
