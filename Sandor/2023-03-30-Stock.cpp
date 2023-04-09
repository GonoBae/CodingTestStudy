#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int days;
        cin >> days;

        vector<int> chart(days);
        for (int i = 0; i < days; ++i)
        {
            cin >> chart[i];
        }

        long long answer = 0;
        int max = chart[chart.size()-1];
        for (int i = chart.size() - 1; i >= 0; --i)
        {
            if (max >= chart[i])
            {
                answer += max - chart[i];
            }
            else
            {
                max = chart[i];
            }
        }

        cout << answer << '\n';
    }

    return 0;
}
