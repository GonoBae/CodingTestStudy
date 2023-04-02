#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int days;
        cin >> days;

        vector<int> chart(days);
        for (int i = 0; i < days; ++i)
        {
            cin >> chart[i];
        }

        int answer = 0;
        while (true)
        {
            auto max = max_element(chart.begin(), chart.end());
            if (max == chart.end()) { break; }

            // 이윤 계산
            int maxIdx = find(chart.begin(), chart.end(), *max) - chart.begin();
            for (int i = 0; i <= maxIdx; ++i)
            {
                answer += *max - chart[i];
            }

            // max까지 요소들 지우기
            chart.erase(chart.begin(), max + 1);
        }

        cout << answer << '\n';
    }
    
    return 0;
}