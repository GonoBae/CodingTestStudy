#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> meeting; // <시작, 끝>
    for (int i = 0; i < n; ++i)
    {
        int start, end;
        cin >> start >> end;
        meeting.push_back({ start, end });
    }

    // 오름차순
    sort(meeting.begin(), meeting.end());

    int answer = 0;
    int time = 0; // 이전 회의가 끝나는 시간
    for (int i = 0; i < n-1; ++i)
    {
        // i 회의가 끝나는 시간이 i+1 회의가 끝나는 시간보다 작을 때
        // i 회의가 시작하는 시간이 time(이전 회의 끝나는 시간) 보다 크거나 같을 때
        if (meeting[i].second <= meeting[i + 1].second && time <= meeting[i].first)
        {
            ++answer;
            time = meeting[i].second;
        }
    }

    // 마지막 회의 처리
    if (time <= meeting[n - 1].first) { ++answer; }
    cout << answer;

    return 0;
}
